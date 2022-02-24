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
char map[25][25];
int vis[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

    scanf("%d\n", &N);
    for (int i=0; i<N; i++) {
        char s[25];
        scanf("%s", s);
        for (int j=0; j<N; j++) 
            map[i][j] = s[j];
    }

    vector<int> v;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == '0' || vis[i][j]) continue;

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

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (map[nx][ny] == '0' || vis[nx][ny]) continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            v.push_back(area);
        }
    }

    printf("%d\n", (int)v.size());
    sort(v.begin(), v.end());
    for (int n : v)
        printf("%d\n", n);
    return 0;
}