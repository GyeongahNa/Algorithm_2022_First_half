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

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int N, M;
int board1[10][10];
int board2[10][10];

int arr[3];
int isused[110];
vector<ii> zero;
int mx;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void setBoard() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            board2[i][j] = board1[i][j];
    }
    
    for (int i=0; i<3; i++)
        board2[zero[arr[i]].X][zero[arr[i]].Y] = 1;
}

void bfs() {

    int visited[10][10];
    memset(visited, 0, sizeof(visited));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board2[i][j] != 2 || visited[i][j]) continue;

            queue<ii> q;
            q.push({i, j});
            visited[i][j] = 1;

            while (!q.empty()) {
                ii cur = q.front();
                q.pop();
                board2[cur.X][cur.Y] = 2;

                for (int i=0; i<4; i++) {
                    int nx = cur.X+dx[i];
                    int ny = cur.Y+dy[i];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (board2[nx][ny] || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
}

int cnt() {

    int re = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!board2[i][j]) re++;
        }
    }
    return re;
}

void func(int k) {

    if (k == 3) {
        setBoard();
        bfs();
        mx = max(mx, cnt());
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<zero.size(); i++) {
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
        for (int j=0; j<M; j++) {
            scanf("%d", &board1[i][j]);
            if (!board1[i][j])
                zero.push_back({i, j});
        }
    }

    func(0);
    printf("%d", mx);
    return 0;
}