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

//dp[i]: i번째 수로 끝나는 증가하는 부분수열 중 최댓값

int N;
int A[1005];
int dp[1005];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &A[i]);

    dp[1] = A[1];
    int ans = dp[1];
    for (int i=2; i<=N; i++) {
        int mx = 0;
        for (int j=1; j<i; j++) {
            if (A[j] < A[i]) mx = max(mx, dp[j]);
        }
        dp[i] = mx+A[i];
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}
