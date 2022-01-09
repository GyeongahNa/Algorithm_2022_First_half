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

int N, M, K;
int map[100][100];
int vis[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d %d %d", &M, &N, &K);
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));

    while (K--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int i=y1; i<y2; i++) {
            for (int j=x1; j<x2; j++) 
                map[i][j] = 1;
        }
    }

    vector<int> v;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j]|| vis[i][j]) continue;

            queue<ii> q;
            q.push({i, j});
            vis[i][j] = 1;

            int area = 0;
            while (!q.empty()) {
                ii cur = q.front();
                q.pop();
                area++;

                for (int i=0; i<4; i++) {
                    int nx = cur.X+dx[i];
                    int ny = cur.Y+dy[i];

                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if (map[nx][ny] != 0 || vis[nx][ny]) continue;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            v.push_back(area);
        }
    }

    printf("%d\n", (int)v.size());
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
    return 0;
}