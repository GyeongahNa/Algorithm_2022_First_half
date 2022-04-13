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

#define X first
#define Y second

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int n, w, L, s, e, t, wt;
ii truck[1005];

int main() {

    cin >> n >> w >> L;
    for (int i=0; i<n; i++) cin >> truck[i].X;

    s = -1, e = -1;
    while (s < n-1) {
        t++;
        int tmp = s;
        for (int i=tmp+1; i<=e; i++) {
            truck[i].Y++;
            if (truck[i].Y < w) continue;
            s++;
            wt -= truck[i].X;
        }
        if (e+1 < n && wt+truck[e+1].X <= L) wt += truck[++e].X;
    }
    cout<<t;
    return 0;
}