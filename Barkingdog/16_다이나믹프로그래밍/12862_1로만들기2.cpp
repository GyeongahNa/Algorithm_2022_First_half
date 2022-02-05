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

int N;
int dp[1000005];
int pre[1000005];

int main() {

    scanf("%d", &N);
    
    dp[1] = 0;
    for (int i=2; i<=N; i++) {
        
        dp[i] = dp[i-1];
        pre[i] = i-1;
        if (!(i%3) && dp[i/3] <= dp[i]) {
            dp[i] = dp[i/3];
            pre[i] = i/3;
        }   
        if (!(i%2) && dp[i/2] <= dp[i]) {
            dp[i] = dp[i/2];
            pre[i] = i/2;
        }
        dp[i]++;
    }

    printf("%d\n", dp[N]);
    while (1) {
        if (N == 0) break;
        printf("%d ", N);
        N = pre[N];
    }
    return 0;
}