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

//dp[i]: i번째 날 부터 상담을 시작했을 때 최대 수익

int N;
int T[1500100];
int P[1500100];
int dp[1500100];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d %d", &T[i], &P[i]);

    for (int i=N; i>=1; i--) {
        if (i+T[i] > N+1) dp[i] = dp[i+1];
        else dp[i] = max(dp[i+1], P[i]+dp[i+T[i]]);
    }

    printf("%d\n", dp[1]);
    return 0;
}