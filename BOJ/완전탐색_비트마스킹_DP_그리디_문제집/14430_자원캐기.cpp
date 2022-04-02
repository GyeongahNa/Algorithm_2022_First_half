#include <cstdio>
#include <cmath>
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

int N, M, mx;
vector<vector<int>> memo(305, vector<int>(305, -1));
vector<vector<int>> board(305, vector<int>(305, 0));

int dfs(int x, int y) {

    if (memo[x][y] != -1) return memo[x][y];
    if (x == N && y == M) return board[N][M];

    for (int i=0; i<2; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
        memo[x][y] = max(memo[x][y], dfs(nx, ny)+board[x][y]);
    }
    return memo[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin >> board[i][j];
    }

    cout<<dfs(1, 1);
    return 0;
}