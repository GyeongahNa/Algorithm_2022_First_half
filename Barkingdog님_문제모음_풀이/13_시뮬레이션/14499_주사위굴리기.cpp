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

int board[30][30];
int dice[6];
int N, M;
int x, y;
int K;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int idx[4][4] = {
    {0, 1, 2, 3},
    {3, 2, 1, 0}, 
    {1, 4, 3, 5},
    {1, 5, 3, 4}
};

void go(int dir) {

    int nx = x+dx[dir];
    int ny = y+dy[dir];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
    x = nx; y = ny;

    int tmp[6]; // 주사위 이동
    for (int i=0; i<6; i++) tmp[i] = dice[i];
    for (int i=0; i<4; i++)
        tmp[idx[dir][(i+1)%4]] = dice[idx[dir][i]];
    for (int i=0; i<6; i++) dice[i] = tmp[i];

    if (!board[x][y]) board[x][y] = dice[3]; //이동한 보드 칸 확인 
    else {
        dice[3] = board[x][y];
        board[x][y] = 0;
    }
    printf("%d\n", dice[1]);
}

int main() {

    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &board[i][j]);
    } 

    while (K--) {
        int cmd;
        scanf("%d", &cmd);
        go(cmd-1);
    }
    return 0;
}

// 이중 배열을 이용하여 주사위의 이동을 더 간결하게 구현할 수 있음
// void go(int dir) {

//     int nx = x+dx[dir];
//     int ny = y+dy[dir];

//     if (nx < 0 || nx >= N || ny < 0 || ny >= M) return;
//     x = nx; y = ny;

//     if (dir == 0) {
//         int tmp = dice[3];
//         for (int i=3; i>0; i--) 
//             dice[i] = dice[i-1];
//         dice[0] = tmp;
//     }
//     else if (dir == 1) {
//         int tmp = dice[0];
//         for (int i=0; i<3; i++)
//             dice[i] = dice[i+1];
//         dice[3] = tmp;
//     }
//     else if (dir == 2) {
//         int tmp = dice[4];
//         dice[4] = dice[1];
//         dice[1] = dice[5];
//         dice[5] = dice[3];
//         dice[3] = tmp;
//     }
//     else {
//         int tmp = dice[3];
//         dice[3] = dice[5];
//         dice[5] = dice[1];
//         dice[1] = dice[4];
//         dice[4] = tmp;
//     }

//     if (!board[x][y]) board[x][y] = dice[3]; //이동한 보드 칸 확인 
//     else {
//         dice[3] = board[x][y];
//         board[x][y] = 0;
//     }
//     printf("%d\n", dice[1]);
// }
