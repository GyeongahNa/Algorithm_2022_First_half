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

#define X first
#define Y second

int T;
int w, h;
char map[1000][1000];
int distF[1000][1000];
int distS[1000][1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &w, &h);
        memset(map, '0', sizeof(map));
        memset(distF, -1, sizeof(distF));
        memset(distS, -1, sizeof(distS));

        queue<ii> qf, qs;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                scanf(" %c", &map[i][j]);
                if (map[i][j] == '@') {
                    qs.push({i, j});
                    distS[i][j] = 0;
                }
                else if (map[i][j] == '*') {
                    qf.push({i, j});
                    distF[i][j] = 0;
                }
            }
        }

        while (!qf.empty()) {
            
            ii cur = qf.front(); //auto cur = qf.front();
            qf.pop();

            for (int i=0; i<4; i++) {
                int nx = cur.X+dx[i];
                int ny = cur.Y+dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (map[nx][ny] == '#' || distF[nx][ny] != -1) continue;
                
                qf.push({nx, ny});
                distF[nx][ny] = distF[cur.X][cur.Y]+1;
            }
        }

        int re = -1;
        while (!qs.empty()) {
            
            ii cur = qs.front();
            qs.pop();

            for (int i=0; i<4; i++) {
                int nx = cur.X+dx[i];
                int ny = cur.Y+dy[i];
                int newdist = distS[cur.X][cur.Y]+1;

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    re = newdist;
                    break;
                }
                if (map[nx][ny] == '#' || distS[nx][ny] != -1) continue;
                if (distF[nx][ny] != -1 && newdist >= distF[nx][ny]) continue;

                qs.push({nx, ny});
                distS[nx][ny] = newdist;
            }
            if (re != -1) break;
        }
        if (re != -1) printf("%d\n", re);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}