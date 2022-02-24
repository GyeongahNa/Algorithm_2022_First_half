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

//dp[i]: i번째 피보나치 수
//dp[i] = dp[i-2]+dp[i-1]

int N;
long long dp[95];

int main() {

    scanf("%d", &N);
    dp[0] = 0; dp[1] = 1;
    for (int i=2; i<=N; i++)
        dp[i] = dp[i-2]+dp[i-1];
    printf("%lld", dp[N]);
    return 0;
}