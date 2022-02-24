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

int N, M;
int box[1000][1000];
int dist[1000][1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    int N, M;
    scanf("%d %d", &M, &N);
    memset(box, 0, sizeof(box));
    memset(dist, -1, sizeof(dist));

    queue<ii> q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (box[nx][ny] != 0 || dist[nx][ny] != -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }

    int re = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (box[i][j] == 0 && dist[i][j] == -1) {
                printf("-1");
                return 0;
            }
            re = max(re, dist[i][j]);
        }
    }
    printf("%d", re);
    return 0;
}

/*시작점이 여러개일 때*/