#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, mx;
vector<ii> v(10);

void breakEgg(int k) {

    if (k == N) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (!v[i].X) cnt++;
        }
        mx = max(mx, cnt);
        return ;
    }

    int nbreakable = 0;
    for (int i=0; i<N; i++) {
        if (k == i) continue;
        if (v[i].X) nbreakable++;
    }

    if (!v[k].X || !nbreakable) breakEgg(k+1);
    else {
        for (int i=0; i<N; i++) {
            if (k == i || !v[i].X) continue;
            int tmp1 = v[k].X, tmp2 = v[i].X;
            v[k].X = max(0, v[k].X-v[i].Y);
            v[i].X = max(0, v[i].X-v[k].Y);
            breakEgg(k+1);
            v[k].X = tmp1; v[i].X = tmp2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> v[i].X;
        cin >> v[i].Y;
    }

    breakEgg(0);
    cout<<mx;
    return 0;
}