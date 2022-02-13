#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<ii> event;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        event.push_back({s, 1});
        event.push_back({e, -1});
    }
    sort(event.begin(), event.end());

    int idx = 0;
    int t = event[0].X;
    int ans = 0;
    int cur = 0;

    while (1) {

        while (idx < 2*N && t == event[idx].X) {
            cur += event[idx].Y;
            idx++;
        }

        ans = max(ans, cur);
        if (idx >= 2*N) break;
        t = event[idx].X;
    }
    printf("%d", ans);
    return 0;
}