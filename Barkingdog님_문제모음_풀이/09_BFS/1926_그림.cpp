/*BFS*/
/*1) Flood Fill*/
/*2) 한 시작점에서 최단 거리 문제*/
/*3) 시작점이 여러개일 때 최단 거리 문제*/
/*4) 시작점의 종류가 다를 때*/
/*5) 1차원에서의 BFS*/

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

int pic[500][500];
bool vis[500][500];

int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int n, m;

int main() {

    scanf("%d %d", &n, &m);
    memset(pic, 0, sizeof(pic));
    memset(vis, false, sizeof(vis));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            scanf("%d", &pic[i][j]);
    }

    int cnt = 0, max_breadth = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!pic[i][j] || vis[i][j]) continue;

            cnt++;
            int breadth = 0;
            queue<ii> q;
            q.push({i, j});
            vis[i][j] = true;
            breadth++;
            
            while (!q.empty()) {

                ii cur = q.front();
                q.pop();

                for (int k=0; k<4; k++) {
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || !pic[nx][ny]) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    breadth++;
                }
            }
            max_breadth = max(max_breadth, breadth);
        }
    } 
    printf("%d\n%d", cnt, max_breadth);
    return 0;
}

/*Flood Fill 문제*/