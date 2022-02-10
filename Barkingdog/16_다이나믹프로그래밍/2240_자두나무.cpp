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

//dp[t][p][w]: t초에 p번 위치에 있을 때 먹을 수 있는 최대 자두 개수(w: 남아있는 이동 가능 횟수)

int T, W;
int dp[1005][3][35];

void dynamic(int t, int p) {

    for (int w=0; w<=W; w++) {
        if (w == W) dp[t][p][w] = dp[t-1][p][w]+1;
        else dp[t][p][w] = max(dp[t-1][p][w], dp[t-1][3-p][w+1])+1;
    }

    for (int w=0; w<=W; w++) {
        if (w == W) dp[t][3-p][w] = dp[t-1][3-p][w];
        else dp[t][3-p][w] = max(dp[t-1][3-p][w], dp[t-1][p][w+1]);
    }
}

int main() {
    
    scanf("%d %d", &T, &W);

    int pos;
    scanf("%d", &pos);
    if (pos == 1) dp[1][1][W] = 1;
    else dp[1][2][W-1] = 1;

    for (int t=2; t<=T; t++) {
        scanf("%d", &pos);
        dynamic(t, pos);
    }

    int ans = 0;
    for (int w=0; w<=W; w++)
        ans = max({ans, dp[T][1][w], dp[T][2][w]});
    printf("%d", ans);
    return 0;
}