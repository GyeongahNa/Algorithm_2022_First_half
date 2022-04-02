#include <cstdio>
#include <cstring>
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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, mx;
bool check[30];
char board[25][25];
bool visited[25][25];

void dfs(int x, int y, int cnt) {

    visited[x][y] = true;
    check[board[x][y]-'A'] = true;
    mx = max(mx, cnt);

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
        if (visited[nx][ny] || check[board[nx][ny]-'A']) continue;
        dfs(nx, ny, cnt+1);
    }

    visited[x][y] = false;
    check[board[x][y]-'A'] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> R >> C;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) cin >> board[i][j];
    }

    dfs(1, 1, 1);
    cout<<mx;
    return 0;
}