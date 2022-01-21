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
#define MX 2147680

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N, K;
int board[15][15];
deque<ii> state[15][15]; // 보드 위의 말 상태 저장, 보드 마다 (말 번호, 방향)으로 이루어진 덱 저장
ii horse[15]; //(x, y) 각 말들의 위치 정보 저장

int red(int x, int y, int k, int nx, int ny) {
    deque<ii> area = state[x][y];
    for (int i=area.size()-1; i>=k; i--) {
        state[nx][ny].push_back(area[i]);
        horse[area[i].X] = {nx, ny};
    }

    for (int i=area.size()-1; i>=k; i--)
        state[x][y].pop_back();

    if (state[nx][ny].size() >= 4) return 1;
    return 0;
}

int white(int x, int y, int k, int nx, int ny) {

    deque<ii> area = state[x][y];
    for (int i=k; i<state[x][y].size(); i++) {
        state[nx][ny].push_back(area[i]);
        horse[area[i].X] = {nx, ny};
    }

    for (int i=area.size()-1; i>=k; i--)
        state[x][y].pop_back();

    if (state[nx][ny].size() >= 4) return 1;
    return 0;
}

int OOB(int x, int y) {
    return x < 1 || x >= N+1 || y < 1 || y >= N+1;
}

int turn() {

    int t = 0;
    while (++t <= 1000) {
        for (int k=0; k<K; k++) {

            deque<ii> area = state[horse[k].X][horse[k].Y];
            for (int i=0; i<area.size(); i++) {
                if (area[i].X != k) continue;
                int dir = area[i].Y;
                int nx = horse[k].X+dx[dir];
                int ny = horse[k].Y+dy[dir];

                int re = 0;
                if (nx < 1 || nx >= N+1 || ny < 1 || ny >= N+1 || board[nx][ny] == 2) {

                    if (dir == 0) dir = 1;
                    else if (dir == 1) dir = 0;
                    else if (dir == 2) dir = 3;
                    else dir = 2;
                    state[horse[k].X][horse[k].Y][i].Y = dir;
                    
                    nx = horse[k].X+dx[dir];
                    ny = horse[k].Y+dy[dir];
                    if (!OOB(nx, ny) && !board[nx][ny]) re = white(horse[k].X, horse[k].Y, i, nx, ny);
                    else if (!OOB(nx, ny) && board[nx][ny] == 1) re = red(horse[k].X, horse[k].Y, i, nx, ny);
                }
                else if (!board[nx][ny]) re = white(horse[k].X, horse[k].Y, i, nx, ny);
                else re = red(horse[k].X, horse[k].Y, i, nx, ny);

                if (re) return t;
            }
        }
    }
    return -1;
}

int main() {

    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    }

    for (int i=0; i<K; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        horse[i] = {x, y};
        state[x][y].push_back({i, --d});
    }

    printf("%d", turn());
    return 0;
}