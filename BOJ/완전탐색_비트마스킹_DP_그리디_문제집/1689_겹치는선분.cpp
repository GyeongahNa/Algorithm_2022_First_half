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

int N;
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, 1});
        v.push_back({e, -1});
    }
    sort(v.begin(), v.end());

    int cnt = 0, mx = 0;
    for (int i=0; i<2*N; i++) {
        cnt += v[i].Y;
        mx = max(mx, cnt);
    }
    cout<<mx;
    return 0;
}