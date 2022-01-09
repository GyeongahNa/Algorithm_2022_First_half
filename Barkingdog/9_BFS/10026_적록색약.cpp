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
char pic[100][100];
int vis[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool differ(char c1, char c2, int normal) {

    if (!normal && ((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R'))) return 0;
    return (c1 != c2);
}

int BFS(int normal) {

    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (vis[i][j]) continue;
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
                    if (differ(pic[cur.X][cur.Y], pic[nx][ny], normal) || vis[nx][ny]) continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return cnt;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf(" %c", &pic[i][j]);
    }

    printf("%d %d", BFS(1), BFS(0));
    return 0;
}