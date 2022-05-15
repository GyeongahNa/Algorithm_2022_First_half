#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int T, H, W, O, F, sx, sy, ex, ey, x, y, L, f;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool bfs(const vector<vector<int>>& board) {

    vector<vector<bool>> visited(105, vector<bool>(105, false));

    queue<iii> q;
    q.push({sx, sy, F});
    visited[sx][sy] = true;

    while (!q.empty()) {

        iii cur = q.front();
        q.pop();
        tie(x, y, f) = cur;
        if (x == ex && y == ey) return true;
        if (f <= 0) continue;
        
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 1 || nx > H || ny < 1 || ny > W) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny]-board[x][y] > f) continue;
            q.push({nx, ny, f-1});
            visited[nx][ny] = true;
        }
    }
    return false;
}

int main() {

    cin >> T;
    while (T--) {
        cin >> H >> W >> O >> F >> sx >> sy >> ex >> ey;
        vector<vector<int>> board(105, vector<int>(105, 0));
        while (O--) {
            cin >> x >> y >> L;
            board[x][y] = L;
        }

        if (bfs(board)) cout<<"잘했어!!"<<"\n";
        else cout<<"인성 문제있어??"<<"\n";
    }
    return 0;
}