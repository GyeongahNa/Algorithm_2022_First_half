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
#define mod 10007

int N, K;
int dp[1005][1005];

int main() {
    
    scanf("%d %d", &N, &K);
    
    for (int i=0; i<=N; i++) dp[i][0] = 1;
    for (int i=1; i<=N; i++) {
        for (int k=1; k<=N; k++)
            dp[i][k] = (dp[i-1][k]+dp[i-1][k-1])%mod;
    }
    printf("%d", dp[N][K]);
    return 0;
}

/*
dp[n][k]: nCk
dp[n][k] = dp[n-1][k]+dp[n-1][k-1]
*/