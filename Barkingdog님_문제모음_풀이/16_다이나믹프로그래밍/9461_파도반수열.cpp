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

//dp[i]: P(i)
//dp[i] = dp[i-3]+dp[i-2]

int T;
long long dp[105];

int main() {

    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for (int i=4; i<=100; i++)
        dp[i] = dp[i-3]+dp[i-2];
    
    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", dp[x]);
    }
    return 0;
}