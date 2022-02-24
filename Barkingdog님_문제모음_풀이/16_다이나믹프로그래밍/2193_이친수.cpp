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

//dp[i]: i자리 이친수의 개수
//dp[i] = dp[i-2]+dp[i-1]

int N;
long long dp[95];

int main() {

    scanf("%d", &N);
    dp[1] = 1; dp[2] = 1;
    for (int i=3; i<=N; i++) 
        dp[i] = dp[i-2]+dp[i-1];
    printf("%lld\n", dp[N]); 
    return 0;
}
