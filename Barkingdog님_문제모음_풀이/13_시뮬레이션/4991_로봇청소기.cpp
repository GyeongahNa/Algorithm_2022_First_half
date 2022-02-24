#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int W, H;
char board[25][25];
vector<ii> vdirty;

int getPos(int nx, int ny) {

    for (int i=0; i<vdirty.size(); i++) {
        if (vdirty[i].X == nx && vdirty[i].Y == ny) return i;
    }
    return 0;
}

int bfs(int x, int y) {

    int dist[25][25][1<<10];
    memset(dist, -1, sizeof(dist));

    queue<iii> q;
    q.push({x, y, 0});
    dist[x][y][0] = 0;

    while (!q.empty()) {
        
        iii cur = q.front();
        q.pop();
        
        int x = get<0>(cur);
        int y = get<1>(cur);
        int pass = get<2>(cur);
        if (pass == (1<<vdirty.size())-1) 
            return dist[x][y][pass];

        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny] == 'x') continue; 

            int p = pass;
            if (board[nx][ny] == '*') p |= (1<<getPos(nx, ny));
            if (dist[nx][ny][p] != -1) continue;
            dist[nx][ny][p] = dist[x][y][pass]+1;
            q.push({nx, ny, p});
        }
    }

    return -1;
}

int main() {
    while (1) {
        scanf("%d %d", &W, &H);
        if (!W || !H) break;

        int x, y;
        vdirty.clear();
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                scanf(" %c", &board[i][j]);
                if (board[i][j] == 'o') {
                    x = i, y = j;
                }
                else if (board[i][j] == '*') 
                    vdirty.push_back({i, j});
            }
        }
        printf("%d\n", bfs(x, y));
    }
    return 0;
}