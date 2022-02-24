#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iic = tuple<int, int, char>;

#define X first
#define Y second

int N, M, ncctv, re;
ii cctv[10];
int map1[10][10];
int map2[10][10];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool OBB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void draw(int x, int y, int dir) {

    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (OBB(x, y) || map2[x][y] == 6) return ;
        if (map2[x][y]) continue;
        map2[x][y] = 7;
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map1[i][j]);
            if (map1[i][j] && map1[i][j] != 6) {
                cctv[ncctv] = {i, j};
                ncctv++;
            }
            if (!map1[i][j]) re++;
        }
    }

    for (int tmp = 0; tmp<(1<<(2*ncctv)); tmp++) {

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++)
                map2[i][j] = map1[i][j];
        }

        int brute = tmp;
        for (int i=0; i<ncctv; i++) {
            int dir = brute % 4;
            brute /= 4;

            int x = cctv[i].X;
            int y = cctv[i].Y;

            if (map1[x][y] == 1) {
                draw(x, y, dir);
            }
            else if (map1[x][y] == 2) {
                draw(x, y, dir);
                draw(x, y, dir+2);
            }
            else if (map2[x][y] == 3) {
                draw(x, y, dir);
                draw(x, y, dir+1);  
            }
            else if (map2[x][y] == 4) {
                draw(x, y, dir);
                draw(x, y, dir+1);
                draw(x, y, dir+2);
            }
            else {
                draw(x, y, dir);
                draw(x, y, dir+1);
                draw(x, y, dir+2);
                draw(x, y, dir+3);
            }
        }

        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (!map2[i][j]) cnt++;
            }
        }
        re = min(cnt, re);
    }

    printf("%d", re);
    return 0;
}
/* 백트래킹으로 풀어도 되는 문제이지만, 4진법을 이용하여 모든 케이스에 대해 각 카메라의 방향을 분리하는 방법으로도 풀이 가능*/
/* draw 함수의 경우 모든 방향에 대해 if 문을 써서 구현하는 것보다, dx, dy 배열을 이용하여 풀면 더 깔끔하게 구현 가능*/