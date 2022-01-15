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

int N, M;
int x, y, d;
int cnt;
int stop;
int board[60][60];
int visited[60][60];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool rotate() {
    
    for (int i=0; i<4; i++) {
        d = (d+3)%4;
        int nx = x+dx[d];
        int ny = y+dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[nx][ny]) continue;
        if (visited[nx][ny]) continue;
        x = nx;
        y = ny;
        return true;
    }
    return false;
}


int main() {

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &x, &y, &d);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &board[i][j]);
    }

    while (1) {

        if (!visited[x][y]) {
            cnt++;
            visited[x][y] = 1;
        }
    
        bool check = rotate();
        if (!check) {
            int nx = x-dx[d];
            int ny = y-dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
            if (board[nx][ny]) break;
            x = nx;
            y = ny;
            rotate();
        }
    }

    printf("%d", cnt);
    return 0;
}