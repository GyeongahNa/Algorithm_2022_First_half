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

int M, N;
int board[505][505];
int memo[505][505];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//dp[x][y]: board[x][y]에서 board[M][N]까지 내리막길로만 이동하는 방법의 수

bool OOB(int x, int y) {
    return x < 1 || x > M || y < 1 || y > N;
}

int dfs(int x, int y) {

    if (x == M && y == N) return 1;
    if (memo[x][y] != -1) return memo[x][y];

    memo[x][y] = 0;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny) || board[nx][ny] >= board[x][y]) continue;
        memo[x][y] += dfs(nx, ny); 
    }
    return memo[x][y];
}

int main() { 

    scanf("%d %d", &M, &N);
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    }

    memset(memo, -1, sizeof(memo));
    printf("%d", dfs(1, 1));
    return 0;
}