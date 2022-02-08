#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T;
int N;
int C[25];
int M;
int dp[10001];

int main() {

    scanf("%d", &T);
    while (T--) {

        scanf("%d", &N);
        for (int i=1; i<=N; i++)
            scanf("%d", &C[i]);
        scanf("%d", &M);
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++)
                if (C[i] <= j) dp[j] += dp[j-C[i]];
        }

        printf("%d\n", dp[M]);
    }
    return 0;
}