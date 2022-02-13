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
pair<ii, ii> flower[100005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        flower[i] = {{x1, y1}, {x2, y2}};
    }
    sort(flower, flower+N);

    int cnt = 0;
    ii t = {3, 1}, mx = {0, 0};
    for (int i=0; i<=N; i++) {
        
        if (i < N && flower[i].X <= t) {
            mx = max(mx, flower[i].Y);
            continue;
        }
        
        if (mx <= t) break;
        
        t = mx;
        cnt++;
        mx = {0, 0};
        if (t > ii({11, 30})) break;
        if (i < N && flower[i].X <= t) mx = flower[i].Y;
    }

    if (t > ii({11, 30})) printf("%d", cnt);
    else printf("0");
}