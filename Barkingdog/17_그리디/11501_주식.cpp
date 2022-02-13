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
using ll = pair<long long, long long>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;
ll stock[1000005];
ll tmp[1000005];

bool cmp(ll a, ll b) {

    if (a.Y != b.Y) return a.Y > b.Y;
    return a.X < b.X;
}

int main() {

    scanf("%d", &T);
    while (T--) {

        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            stock[i].X = i;
            scanf("%lld", &stock[i].Y);
            tmp[i].X = i;
            tmp[i].Y = stock[i].Y;
        }
        
        stable_sort(tmp, tmp+N, cmp);

        int i = 0, j = 0;
        long long re = 0;
        while (j < N) {
            int k = i;
            while (k <= tmp[j].X) {
                re += (tmp[j].Y-stock[k].Y);
                k++;
            }
            i = k;
            j++;
        }
        printf("%lld\n", re);
    }
    return 0;
}