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
ii line[1000005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d %d", &line[i].X, &line[i].Y);
    sort(line, line+N);

    int re = 0;
    int st = line[0].X;
    int en = line[0].Y;
    for (int i=1; i<=N; i++) {
        if (i < N && line[i].X <= en) {
            en = max(en, line[i].Y);
            continue;
        }

        re += en-st;
        if (i == N) break;
        st = line[i].X;
        en = line[i].Y;
    }
    printf("%d", re);
    return 0;
}