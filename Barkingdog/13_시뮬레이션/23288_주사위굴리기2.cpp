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

int N, M, K;
int board[25][25];
int x, y, d;

int dice[6] = {4, 1, 3, 6, 2, 5};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};


bool OOB(int nx, int ny) {
    return nx < 0 || nx >= N || ny < 0 || ny >= M;
}


int opposite() {

    if (d == 0) return 2;
    if (d == 1) return 3;
    if (d == 2) return 0;
    return 1;
 }   


void moveDice() {

    if (OOB(x+dx[d], y+dy[d])) 
        d = opposite();

    if (d == 0) {
        int tmp = dice[3];
        for (int i=3; i>0; i--)
            dice[i] = dice[i-1];
        dice[0] = tmp;
    }
    else if (d == 2) {
        int tmp = dice[0];
        for (int i=0; i<3; i++)
            dice[i] = dice[i+1];
        dice[3] = tmp;
    }
    else if (d == 1) {
        int tmp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[3];
        dice[3] = tmp;
    }
    else if (d == 3) {
        int tmp = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    }
    x += dx[d];
    y += dy[d];
}


int bfs() {

    bool visited[25][25] = {};

    queue<ii> q;
    q.push({x, y});
    visited[x][y] = true;

    int cnt = 0;
    while (!q.empty()) {

        ii cur = q.front();
        q.pop();
        cnt++;

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (OOB(nx, ny) || visited[nx][ny]) continue;
            if (board[nx][ny] != board[cur.X][cur.Y]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt;
}


void rotateDir(int A, int B) {

    if (A == B) return;
    if (A > B) d = (d+3)%4;
    else d = (d+1)%4;
    return ;
}


int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) 
            scanf("%d", &board[i][j]);
    }

    x = 0, y = 0, d = 0;
    
    int score = 0;
    while (K--) {
        moveDice();
        int A = dice[3];
        int B = board[x][y];
        int C = bfs();
        score += B*C;
        rotateDir(A, B);
    }
    printf("%d", score);
    return 0;
}