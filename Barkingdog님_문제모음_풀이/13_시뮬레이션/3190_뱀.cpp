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

int N, K, L;
int board[120][120];
int snake[120][120];
int dirs[10100];
int t, d;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i=0; i<K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r-1][c-1] = 1;
    }

    scanf("%d", &L);
    for (int i=0; i<L; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        dirs[x] = (c == 'L') ? -1 : 1;
    }

    deque<ii> dq;
    dq.push_back({0, 0});
    snake[0][0] = 1;
    d = 1;

    while (1) {
        
        t++;

        ii cur = dq.front();
        int nx = cur.X+dx[d];
        int ny = cur.Y+dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || snake[nx][ny]) break;

        snake[nx][ny] = 1;
        dq.push_front({nx, ny});

        if (board[nx][ny]) board[nx][ny] = 0;
        else {
            ii tail = dq.back();
            snake[tail.X][tail.Y] = 0;
            dq.pop_back();
        }

        if (dirs[t] == -1) d = (d+3)%4;
        if (dirs[t] == 1) d = (d+1)%4;
    }
    printf("%d", t);
    return 0;
}