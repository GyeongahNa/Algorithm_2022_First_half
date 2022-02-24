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
int dy[4] = {0, 0, 1, -1};

int R, C, M, re;
vector<iii> board[110][110]; 

void catchShark(int col) {

    for (int i=0; i<R; i++) {
        if (!board[i][col].size()) continue;
        re += get<0>(board[i][col][0]);
        board[i][col].clear();
        return ;
    }
}

void moveShark() {

    vector<iii> tmp[110][110] = {};

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (!board[i][j].size()) continue;
            for (int k=0; k<board[i][j].size(); k++) {
                
                int x = i, y = j;
                int size = get<0>(board[i][j][k]);
                int speed = get<1>(board[i][j][k]);
                int dir = get<2>(board[i][j][k]);
                
                if (dir == 0 || dir == 1) speed %= 2*(R-1);
                else speed %= 2*(C-1);

                int step = 0;
                while (step < speed) {
                    int nx = x+dx[dir];
                    int ny = y+dy[dir];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                        if (dir == 0) dir = 1;
                        else if (dir == 1) dir = 0;
                        else if (dir == 2) dir = 3;
                        else dir = 2;
                        continue;
                    }
                    x = nx;
                    y = ny;
                    step++;
                }

                tmp[x][y].push_back({size, speed, dir});
            }
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            board[i][j].clear();
            if (!tmp[i][j].size()) continue;
            sort(tmp[i][j].begin(), tmp[i][j].end(), greater<iii>()); //가장 큰 상어만 살아남으므로 내림차순 정렬
            board[i][j].push_back({tmp[i][j][0]});
        }
    }
}

int main() {
    
    scanf("%d %d %d", &R, &C, &M);
    for (int i=0; i<M; i++) {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        r--; c--; d--;
        board[r][c].push_back({z, s, d});
    }

    for (int i=0; i<C; i++) { //열 개수만큼 이동
        catchShark(i); //i번째 열의 상어 잡아먹기
        moveShark();
    }
    printf("%d", re);
    return 0;
}