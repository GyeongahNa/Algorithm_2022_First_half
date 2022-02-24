#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N;
int board[25][25];
int x, y, t;
int sz = 2;

bool bfs() {

    int dist[25][25];
    memset(dist, -1, sizeof(dist));

    queue<ii> q;
    q.push({x, y});
    dist[x][y] = 0;

    vector<iii> v;
    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] > sz || dist[nx][ny] != -1) continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            if (board[nx][ny] && board[nx][ny] < sz) 
                v.push_back({dist[nx][ny], nx, ny});   
        }
    }

    if (!v.size()) return false;

    sort(v.begin(), v.end());
    x = get<1>(v[0]);
    y = get<2>(v[0]);
    t += get<0>(v[0]);
    board[x][y] = 0;
    return true;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9) {
                x = i; y = j;
                board[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    while (1) {
        if (!bfs()) break;
        cnt++;
        if (sz == cnt) {
            cnt = 0;
            sz++;
        }
    }
    printf("%d", t);
    return 0;
}