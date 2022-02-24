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
#define MX __LONG_LONG_MAX__

//dp[i]: i를 주어진 숫자들의 합으로 나타내는 최소 횟수

int N, K;

int C[105];
int sz;
bool check[100005];
long long dp[10005];

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if (check[x]) continue;
        C[sz++] = x;
        check[x] = true;
    }

    dp[0] = 0;
    for (int i=1; i<=K; i++) {
        long long mn = MX;
        for (int j=0; j<sz; j++) {
            if (C[j] > i || dp[i-C[j]] == -1) continue;
            mn = min(mn, dp[i-C[j]]);
        }
        if (mn == MX) dp[i] = -1;
        else dp[i] = mn+1;
    }
    printf("%lld", dp[K]);
    return 0;
}