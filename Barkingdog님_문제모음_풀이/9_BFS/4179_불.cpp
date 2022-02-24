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

int R, C;
char maze[1000][1000];
int distF[1000][1000];
int distJ[1000][1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d %d", &R, &C);
    memset(distF, -1, sizeof(distF));
    memset(distJ, -1, sizeof(distJ));
    
    queue<ii> fq, jq;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == 'F') {
                fq.push({i, j});
                distF[i][j] = 0;
            }
            else if (maze[i][j] == 'J') {
                jq.push({i, j});
                distJ[i][j] = 0;
            }
        }
    }

    while (!fq.empty()) {
        
        ii cur = fq.front();
        fq.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (maze[nx][ny] == '#' || distF[nx][ny] != -1) continue;
            
            fq.push({nx, ny});
            distF[nx][ny] = distF[cur.X][cur.Y]+1;
        }
    }

    while (!jq.empty()) {

        ii cur = jq.front();
        jq.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (maze[nx][ny] == '#' || distJ[nx][ny] != -1) continue;
            int newdist = distJ[cur.X][cur.Y]+1;
            if (distF[nx][ny] != -1 && newdist >= distF[nx][ny]) continue;
            
            jq.push({nx, ny});
            distJ[nx][ny] = newdist;
        }
    }

    int re = 1000000000;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (i != 0 && i != R-1 && j != 0 && j != C-1) continue;
            if (distJ[i][j] != -1) re = min(re, distJ[i][j]);
        }
    }
    if (re == 1000000000) printf("IMPOSSIBLE");
    else printf("%d", re+1);
    return 0;
}

/*시작점이 두 종류일때(A가 B의 영향을 받을 때)*/
/*A와 B가 동시에 영향을 주고 받는 경우 BFS + 백트래킹*/