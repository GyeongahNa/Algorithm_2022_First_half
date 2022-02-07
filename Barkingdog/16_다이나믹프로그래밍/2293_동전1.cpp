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

//DP[i][j]: i번째 수까지 사용하여 j를 만드는 방법의 수
//메모리 절약을 위해 DP[j]에 계속 덮어씀

int N, K;
int C[101];
int dp[10001];

int main() {

    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) scanf("%d", &C[i]);

    dp[0] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=K; j++) {
            if (C[i] <= j) dp[j] += dp[j-C[i]];
        }
    }

    printf("%d", dp[K]);
    return 0;
}