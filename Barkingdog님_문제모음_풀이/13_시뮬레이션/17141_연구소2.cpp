#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>
#include <map>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
int board[60][60];

int arr[15];
vector<ii> place;
int isused[300];

int mn = MX;

void bfs() {
    
    int dist[60][60];
    memset(dist, -1, sizeof(dist));

    queue<ii> q;
    for (int i=0; i<M; i++) {
        q.push(place[arr[i]]);
        dist[place[arr[i]].X][place[arr[i]].Y] = 0;
    }

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }

    int t = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] == 1) continue;
            if (dist[i][j] == -1) return ;
            t = max(t, dist[i][j]);
        }
    }
    mn = min(mn, t);
}

void func(int k) {

    if (k == M) {
        bfs();
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<place.size(); i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 2) place.push_back({i, j});
        }
    }
    func(0);
    if (mn == MX) printf("-1");
    else printf("%d", mn);
    return 0;
}