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

//dp[i][j]: i번째 집을 j번째 색으로 칠할 때까지의 최소 비용
//dp[i][0] = min(dp[i-1][1], dp[i-1][2])+v[i][0]
//dp[i][1] = min(dp[i-1][0], dp[i-1][2])+v[i][1]
//dp[i][2] = min(dp[i-1][0], dp[i-1][1])+v[i][2]

int N;
int v[1005][3];
int dp[1005][3];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
    
    dp[1][0] = v[1][0]; 
    dp[1][1] = v[1][1];
    dp[1][2] = v[1][2];

    for (int i=2; i<=N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2])+v[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2])+v[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1])+v[i][2];
    }

    printf("%d", min({dp[N][0],dp[N][1], dp[N][2]}));
    return 0;
}