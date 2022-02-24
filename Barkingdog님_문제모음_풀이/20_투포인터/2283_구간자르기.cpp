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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
vector<ii> v;

ii twoPointer() {

    int st = 0;
    int en = 0;
    int lim = 1000001;
    int tot = 0;

    while (st < lim) {

        while (en < lim && tot < K) {
            for (int i=0; i<N; i++) {
                if (en > v[i].X && v[i].Y >= en) tot++;
            }
            en++;
        }
        if (tot == K) return {st, en-1};
        for (int i=0; i<N; i++) {
            if (st >= v[i].X && v[i].Y > st) tot--;
        }
        st++;
    }
    return {0, 0};
}

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }

    ii re = twoPointer();
    printf("%d %d", re.X, re.Y);
    return 0;
}