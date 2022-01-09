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

int K;
int W, H;
int map[200][200];
int dist[200][200][30];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int hdx[8] = {-2, -1, -2, -1, +2, +1, +2, +1};
int hdy[8] = {-1, -2, +1, +2, -1, -2, +1, +2};

int main() {

    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    memset(dist, -1, sizeof(dist));

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++)
            scanf("%d", &map[i][j]);
    }

    queue<iii> q;
    q.push({0, 0, K});
    dist[0][0][K] = 0;

    while (!q.empty()) {

        iii cur = q.front();
        q.pop();

        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int leftK = get<2>(cur);

        if (curX == H-1 && curY == W-1) {
            printf("%d", dist[curX][curY][leftK]);
            return 0;
        }

        for (int i=0; i<4; i++) {
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (map[nx][ny] || dist[nx][ny][leftK] != -1) continue;
            q.push({nx, ny, leftK});
            dist[nx][ny][leftK] = dist[curX][curY][leftK]+1;
        }

        if (leftK > 0) {
            for (int i=0; i<8; i++) {
                int nx = curX+hdx[i];
                int ny = curY+hdy[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (map[nx][ny] || dist[nx][ny][leftK-1] != -1) continue;
                q.push({nx, ny, leftK-1});
                dist[nx][ny][leftK-1] = dist[curX][curY][leftK]+1;
            }
        }
    }
    printf("-1");
    return 0;
}