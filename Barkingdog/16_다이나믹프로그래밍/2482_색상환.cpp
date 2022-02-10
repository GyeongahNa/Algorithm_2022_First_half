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
#define mod 1000000003

//dp[i][j][m][n]: 인덱스 i까지 색상 n개를 선택하는 경우의 수(j: 본인 포함 여부, m: 첫째 색상 포함 여부)
//ans = dp[N][1][0][K]+dp[N][0][1][K]+dp[N][0][0]

int N, K;
int dp[1005][2][2][1005];

int main() {

    scanf("%d %d", &N, &K);

    dp[1][1][1][1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i][1][0][1] = 1;
        dp[i][0][1][1] = 1;
        dp[i][0][0][1] = i-2;
    }
    
    for (int k=2; k<=K; k++) {
        for (int i=3; i<=N; i++) {
            dp[i][0][0][k] = (dp[i-1][0][0][k]+dp[i-1][1][0][k])%mod;
            dp[i][0][1][k] = (dp[i-1][0][1][k]+dp[i-1][1][1][k])%mod;
            dp[i][1][0][k] = (dp[i-2][0][0][k-1]+dp[i-2][1][0][k-1])%mod;
            dp[i][1][1][k] = (dp[i-2][0][1][k-1]+dp[i-2][1][1][k-1])%mod;
        }
    }

    printf("%d", ((dp[N][1][0][K]+dp[N][0][1][K])%mod+dp[N][0][0][K])%mod);
    return 0;
}