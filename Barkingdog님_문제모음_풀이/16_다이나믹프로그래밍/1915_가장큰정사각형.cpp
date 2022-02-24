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

//dp[i][j]: m[i][j]를 우측하단 꼭짓점으로 하는 최대 정사각형의 변의 길이

int N, M;
int m[1005][1005];
int dp[1005][1005];

int main() {

    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++) {
        char s[1005];
        scanf("%s", s);
        for (int j=1; j<=M; j++) {
            if (s[j-1] == '1') m[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (!m[i][j]) continue;
            dp[i][j] = min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]})+1;
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans*ans);
    return 0;
}