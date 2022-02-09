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

int N, M;
int board[1025][1025];
long long dp[1025][1025];

//dp[i][j]: board[i][0]부터 board[i][j] 까지의 누적합

int main() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    }

    for (int i=1; i<=N; i++) {
        dp[i][1] = board[i][1];
        for (int j=2; j<=N; j++) 
            dp[i][j] = dp[i][j-1]+board[i][j];
    }

    while (M--) {

        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        long long re = 0;
        for (int i=x1; i<=x2; i++)
            re += (dp[i][y2]-dp[i][y1-1]);
        printf("%lld\n", re);
    }
    return 0;
}
