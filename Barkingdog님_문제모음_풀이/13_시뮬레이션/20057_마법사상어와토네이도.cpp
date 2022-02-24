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


int N, re;
int p[4][5][5];
int board[505][505];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int sand[5][5] = {
    {0, 0, 2, 0, 0}, 
    {0, 10, 7, 1, 0}, 
    {5, 0, 0, 0, 0},  
    {0, 10, 7, 1, 0}, 
    {0, 0, 2, 0, 0}};


void getProportion(int k) {

    if (k == 0) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) 
                p[k][i][j] = sand[i][j];
        }
        return ;
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++)
            p[k][i][j] = p[k-1][j][4-i];
    }
}


bool OOB(int x, int y) {
    return (x < 0 || x >= N || y < 0 || y >= N);
}


void scatter(int x, int y, int d) {

    int tox = x+dx[d];
    int toy = y+dy[d];
    int amount = board[tox][toy];
    int used = 0;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (!p[d][i][j]) continue;
            
            int tmp = amount*p[d][i][j]/100; 
            if (OOB(tox+i-2, toy+j-2)) re += tmp;
            else board[tox+i-2][toy+j-2] += tmp;
            used += tmp;
        }
    }

    if (OOB(tox+dx[d], toy+dy[d])) re += (amount-used);
    else board[tox+dx[d]][toy+dy[d]] += (amount-used);
    board[tox][toy] = 0;
}


void rotate() {

    int x = N/2, y = N/2;
    int k = 1, t = 0, cnt = 0, d = 0;

    while (1) {

        scatter(x, y, d);

        x += dx[d]; y += dy[d]; t++;
        if (x < 0 || x >= N || y < 0 || y >= N) break;
        if (t == k) {
            d = (d+1)%4;
            cnt++;
            t = 0;
        }
        if (cnt >= 2) {
            k++;
            cnt = 0;
        }
    }
    printf("%d", re);
    return ;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }
    
    for (int i=0; i<4; i++) getProportion(i);
    rotate();
    return 0;
}   