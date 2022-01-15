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

int N, M;
int board[600][600];
int mx;

ii t[7][4] = { 
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, 
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, 
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, 
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}},
    {{0, 0}, {-1, 0}, {-1, 1}, {-2, 1}}};

void rotate() {

    int tmp[600][600] = {};

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            tmp[M-1-j][i] = board[i][j];
    }

    swap(N, M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            board[i][j] = tmp[i][j];
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) 
            scanf("%d", &board[i][j]);
    }

    for (int r=0; r<4; r++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                for (int k=0; k<7; k++) {
                    int s = 0;
                    for (int l=0; l<4; l++) {
                        int nx = i+t[k][l].X;
                        int ny = j+t[k][l].Y;
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
                        s += board[i+t[k][l].X][j+t[k][l].Y];
                    }
                    mx = max(s, mx);
                }
            }
        }
        rotate();
    }
    printf("%d", mx);
    return 0;
}