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
#define half 1000000
#define mod 1000000000

int N;
int dp[2000005];

int main() {

    scanf("%d", &N);
    dp[half] = 0;
    dp[half+1] = 1;
    for (int i=half+2; i<=2*half; i++) 
        dp[i] = (dp[i-2]+dp[i-1])%mod;
    for (int i=half-1; i>=0; i--) 
        dp[i] = (dp[i+2]-dp[i+1])%mod;

    if (dp[N+half] < 0) printf("-1\n");
    else if (dp[N+half] > 0) printf("1\n");
    else printf("0\n");
    printf("%d", abs(dp[N+half]));
    return 0;
}