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

int N;
int dp[35];

//dp[i]: 3*N을 채우는 방법의 수

int main() {

    scanf("%d", &N);

    dp[2] = 3;
    int tot = 0;
    for (int i=4; i<=N; i++) {
        if (i%2) continue;
        dp[i] = dp[2]*dp[i-2]+2*tot+2;
        tot += dp[i-2];
    }

    printf("%d", dp[N]);
    return 0;
}