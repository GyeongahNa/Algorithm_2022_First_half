#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M, K;
vector<iii> board[55][55];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void moveball(int x, int y, iii ball, vector<iii> tmp[55][55]) {

    int m = get<0>(ball);
    int s = get<1>(ball);
    int d = get<2>(ball);

    for (int i=0; i<s; i++) {
        int nx = x+dx[d];
        int ny = y+dy[d];

        if (nx < 1) nx = N;
        else if (nx > N) nx = 1;
        if (ny < 1) ny = N;
        else if (ny > N) ny = 1;

        x = nx;
        y = ny;
    }

    tmp[x][y].push_back({m, s, d});
}

void move() {

    vector<iii> tmp[55][55] = {};

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=0; k<board[i][j].size(); k++)
                moveball(i, j, board[i][j][k], tmp);
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            board[i][j].clear();
            board[i][j] = tmp[i][j];
        }
    }
}

void concat() {

     for (int i=1; i<=N; i++) {
         for (int j=1; j<=N; j++) {
            if (board[i][j].size() < 2) continue;

            int msum = 0, ssum = 0, iseven = 1, isodd = 1;
            for (int k=0; k<board[i][j].size(); k++) {
                iii ball = board[i][j][k];
                msum += get<0>(ball);
                ssum += get<1>(ball);
                if (get<2>(ball)%2) iseven = 0;
                else isodd = 0;
            }

            int m = msum/5, s = ssum/(int)board[i][j].size();
            int d = (iseven || isodd) ? 0 : 1;
            board[i][j].clear();
            if (m) {
                for (int k=0; k<4; k++)
                    board[i][j].push_back({m, s, d+2*k});
            }
         }
     }
}

int getSum() {

    int re = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=0; k<board[i][j].size(); k++) 
                re += get<0>(board[i][j][k]);
        }
    }
    return re;
}

int main() {
    
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<M; i++) {
        int r, c, m, s, d;
        scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
        board[r][c].push_back({m, s, d});
    }

    while (K--) {
        move();
        concat();
    }

    printf("%d", getSum());
    return 0;
}