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

#define X first
#define Y second

int N;
int board1[30][30];
int board2[30][30];
int concat[30][30];
int mx;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int pownum(int n, int k) {

    int re = 1;
    for (int i=0; i<k; i++)
        re *= n;
    return re;
}

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}

void move(int x, int y, int dir) {

    int content = board2[x][y];
    board2[x][y] = 0;

    while (1) {
        x += dx[dir];
        y += dy[dir];

        if (OOB(x, y) || (board2[x][y] && board2[x][y] != content) || concat[x][y]) {
            board2[x-dx[dir]][y-dy[dir]] = content;
            return ;
        }

        if (board2[x][y] == content) {
            board2[x][y] = content*2;
            concat[x][y] = 1;
            return ;
        }
    }
}

void step(int dir) {

    memset(concat, 0, sizeof(concat)); 

    if (dir == 0 || dir == 3) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!board2[i][j]) continue;
                move(i, j, dir);
            }
        }
    }
    else if (dir == 1 || dir == 2) {
        for (int i=N-1; i>=0; i--) {
            for (int j=N-1; j>=0; j--) {
                if (!board2[i][j]) continue;
                    move(i, j, dir);
            }
        }
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &board1[i][j]);
            mx = max(mx, board1[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) 
            board2[i][j] = board1[i][j];
    }

    int ncases = pownum(4, 5);
    for (int tmp=0; tmp<ncases; tmp++) {

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) 
                board2[i][j] = board1[i][j];
        }
        
        int brute = tmp;
        for (int i=0; i<5; i++) {   
            int dir = brute%4;
            brute /= 4;
            step(dir);
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                mx = max(mx, board2[i][j]);
        }
    }

    printf("%d", mx);
    return 0;
}