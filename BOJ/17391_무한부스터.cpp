#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int N, M;
int board[305][305];
int memo[305][305];

int dfs(int x, int y) {

    if (memo[x][y]) return memo[x][y];
    if (x == N && y == M) return 0;

    memo[x][y] = N*M;
    for (int i=0; i<2; i++) {
        for (int j=1; j<=board[x][y]; j++) {
            int nx = x+dx[i]*j;
            int ny = y+dy[i]*j;
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            memo[x][y] = min(memo[x][y], dfs(nx, ny)+1);
        }
    }
    return memo[x][y];
}

int main () {

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin >> board[i][j];
    }

    cout<<dfs(1, 1);
    return 0;
}