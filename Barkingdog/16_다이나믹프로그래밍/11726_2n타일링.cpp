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
int dp[1005];

int main() {

    scanf("%d", &N);
    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=N; i++)
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    printf("%d", dp[N]);
    return 0;
}