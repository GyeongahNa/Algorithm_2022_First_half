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

//dp[i]: i번째 원소까지의 최대 연속합(i번째 원소 포함)
//dp[i] = max(dp[i-1]+v[i], v[i])


int N;
int dp[100005];
int v[100005];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &v[i]);

    dp[1] = v[1];
    for (int i=2; i<=N; i++)
        dp[i] = max(dp[i-1]+v[i], v[i]);

    int ans = dp[1];
    for (int i=2; i<=N; i++) ans = max(dp[i], ans);
    printf("%d\n", ans);
    return 0;    
}