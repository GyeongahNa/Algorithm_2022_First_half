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

//dp[i]: 카드 i장을 살때 최대 금액

int N;
int P[1005];
int dp[1005];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &P[i]);

    dp[1] = P[1];
    for (int i=2; i<=N; i++) {
        dp[i] = P[i];
        for (int j=1; j<i; j++)
            dp[i] = max(dp[i], P[j]+dp[i-j]);
    }

    printf("%d", dp[N]);
    return 0;
}