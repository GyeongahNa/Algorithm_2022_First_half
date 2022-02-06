#include <cstdio>
#include <cstring>
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

//dp[i][j]: j로 끝나는 길이가 i인 계단수의 개수

int N;
int dp[105][10];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=9; i++) dp[1][i] = 1;
    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            if (j == 0) dp[i][j] = dp[i-1][1];
            else if (j == 9) dp[i][j] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        }
    }

    int ans = 0;
    for (int i=0; i<=9; i++) ans = (ans+dp[N][i])%1000000000;
    printf("%d\n", ans);
    return 0;
}