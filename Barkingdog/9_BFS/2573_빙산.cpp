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
int map[300][300];
int near[300][300];
int vis[300][300];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &map[i][j]);
    }
    
    for (int y=0; y<=20000; y++) {

        int cnt = 0;
        memset(vis, 0, sizeof(vis));

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (!map[i][j] || vis[i][j]) continue;
                cnt++;

                queue<ii> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    ii cur = q.front();
                    q.pop();

                    for (int i=0; i<4; i++) {
                        int nx = cur.X+dx[i];
                        int ny = cur.Y+dy[i];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (!map[nx][ny] || vis[nx][ny]) continue;

                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        if (cnt >= 2) {
            printf("%d", y);
            return 0;
        }

        memset(near, 0, sizeof(near));
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (!map[i][j]) continue;

                for (int k=0; k<4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (map[nx][ny]) continue;
                    near[i][j]++;
                }
            }
        }

        bool melted = true;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                map[i][j] = max(0, map[i][j]-near[i][j]);
                if (map[i][j] > 0) melted = false;
            }
        }
        if (melted) break;
    }
    printf("0");
    return 0;
}