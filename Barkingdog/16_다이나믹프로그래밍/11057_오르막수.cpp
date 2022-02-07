#include <cstdio>
#include <cstring>
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

//dp[i][j]: j로 끝나는 i자리 오르막수의 개수

int N;
int dp[1001][10];

int main() {

    scanf("%d", &N);
    for (int i=0; i<=9; i++) dp[1][i] = 1;
    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<=j; k++)
                dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
        }
    }

    int re = 0;
    for (int i=0; i<=9; i++) re = (re+dp[N][i])%mod;
    printf("%d", re);
    return 0;
}