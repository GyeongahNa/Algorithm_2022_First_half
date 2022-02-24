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
char map[1000][1000];
int dist[1000][1000][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d %d\n", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf(" %c", &map[i][j]);
    }
    memset(dist, -1, sizeof(dist));

    queue<iii> q;
    q.push({0, 0, 1});
    dist[0][0][1] = 0;
    
    while (!q.empty()) {

        iii cur = q.front();
        q.pop();

        int curx = get<0>(cur);
        int cury = get<1>(cur);
        int block = get<2>(cur);

        if (curx == N-1 && cury == M-1) {
            printf("%d", dist[curx][cury][block]+1);
            return 0;
        }

        for (int i=0; i<4; i++) {
            int nx = curx+dx[i];
            int ny = cury+dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == '1' && !block) continue;
            if (map[nx][ny] == '1' && dist[nx][ny][0] != -1) continue;
            if (map[nx][ny] == '0' && dist[nx][ny][block] != -1) continue;

            if (map[nx][ny] == '1') {
                q.push({nx, ny, 0});
                dist[nx][ny][0] = dist[curx][cury][block]+1;
            }
            else {
                q.push({nx, ny, block});
                dist[nx][ny][block] = dist[curx][cury][block]+1;
            }
        }
    }
    printf("-1");
    return 0;
}