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

int N;
int map[100][100];
int vis[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d", &N);

    int minh = 101, maxh = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            minh = min(minh, map[i][j]);
            maxh = max(maxh, map[i][j]);
        }
    }

    int re = 1;
    for (int h=minh; h<maxh; h++) {

        int tmp[100][100];
        int vis[100][100];
        memset(vis, 0, sizeof(vis));
    
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (map[i][j] <= h) tmp[i][j] = 0;
                else tmp[i][j] = 1;
            }
        }

        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!tmp[i][j] || vis[i][j]) continue;
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

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (!tmp[nx][ny] || vis[nx][ny]) continue;

                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        re = max(cnt, re);
    }
    printf("%d", re);
    return 0;
}