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

//dp[i]: i번째 수로 끝나는 가장 긴 증가하는 부분 수열의 길이

int N;
int A[1005];
int dp[1005];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    
    dp[1] = 1;
    int ans = dp[1];
    for (int i=2; i<=N; i++) {
        int mx = 0;
        for (int j=1; j<i; j++) {
            if (A[j] < A[i]) mx = max(dp[j], mx);
        }
        dp[i] = mx+1;
        ans = max(dp[i], ans);
    }
    printf("%d", ans);
    return 0;
}