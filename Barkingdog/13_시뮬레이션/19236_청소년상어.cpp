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

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

ii board[4][4]; //물고기 번호와 방향
ii fish[17]; // 각 물고기의 좌표
int re;

void moveFish() {

    for (int i=1; i<=16; i++) {

        int x = fish[i].X;
        int y = fish[i].Y;
        int d = board[x][y].Y;
        if (x == -1 || y == -1) continue; 

        for (int j=d; j<d+8; j++) {

            int nx = x+dx[j%8];
            int ny = y+dy[j%8];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (!board[nx][ny].X) continue;

            if (board[nx][ny].X == -1 && board[nx][ny].Y == -1) {
                board[nx][ny].X = i;
                board[nx][ny].Y = j%8;
                board[x][y].X = -1;
                board[x][y].Y = -1;
                fish[i].X = nx;
                fish[i].Y = ny;
                break;
            }

            // swap 함수를 써서 간단히 구현 가능
            int tmpn = board[nx][ny].X;
            int tmpd = board[nx][ny].Y;
            board[nx][ny].X = i;
            board[nx][ny].Y = j%8;
            fish[i].X = nx;
            fish[i].Y = ny;
            board[x][y].X = tmpn;
            board[x][y].Y = tmpd;
            fish[tmpn].X = x;
            fish[tmpn].Y = y;
            break;
        } 
    }
}

void func(int score) {

    moveFish();

    int x = fish[0].X;
    int y = fish[0].Y;
    int d = board[x][y].Y;

    ii tmpb[4][4];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) 
            tmpb[i][j] = board[i][j];
    }

    ii tmpf[17];
    for (int i=0; i<17; i++)
        tmpf[i] = fish[i];

    int nx = x, ny = y, cnt = 0;
    for (int step=0; ;step++) {
        
        nx += dx[d];
        ny += dy[d];
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if (board[nx][ny].X == -1 && board[nx][ny].Y == -1) continue;

        cnt++;
        int fn = board[nx][ny].X;
        
        score += fn;
        board[nx][ny].X = 0;
        fish[0].X = nx;
        fish[0].Y = ny;
        board[x][y].X = -1;
        board[x][y].Y = -1;
        fish[fn].X = -1;
        fish[fn].Y = -1;

        func(score);
        score -= fn;
        
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                board[i][j] = tmpb[i][j];
        }
        for (int i=0; i<17; i++) 
            fish[i] =tmpf[i];
    }

    if (!cnt) {
        re = max(re, score);
        return ;
    }
}


int main() {

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int n, d;
            scanf("%d %d", &n, &d);
            board[i][j] = {n, --d}; 
            fish[n] = {i, j};
        }
    }

    int score = board[0][0].X;
    fish[score] = {-1, -1};
    board[0][0].X = 0;

    func(score);
    printf("%d", re);
    return 0;
}

/*int dx[4], int dy[4] 초기화 부분에서 실수*/
/*백트래킹 구현시 for문을 돌 때 이전 이전의 배열 변경 사항을 모두 철회해주는 작업이 필요 -> tmp 배열들을 사용하여 구현*/
