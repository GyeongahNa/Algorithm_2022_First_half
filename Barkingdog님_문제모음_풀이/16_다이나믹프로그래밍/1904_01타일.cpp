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
#define mod 15746

//dp[i][0]: 0으로 끝나는 N자리 이진수 개수
//dp[i][1]: 1로 끝나는 N자리 이진수 개수

//dp[i][0] = dp[i-2][0]+dp[i-2][1]
//dp[i][1] = dp[i-1][0]+dp[i-1][1]

int N;
int dp[1000005][2];

int main() {

    scanf("%d", &N);
    
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 1;

    for (int i=3; i<=N; i++) {
        dp[i][0] = (dp[i-2][0]+dp[i-2][1])%mod;
        dp[i][1] = (dp[i-1][0]+dp[i-1][1])%mod;
    }
    printf("%d", (dp[N][0]+dp[N][1])%mod);
    return 0;
}