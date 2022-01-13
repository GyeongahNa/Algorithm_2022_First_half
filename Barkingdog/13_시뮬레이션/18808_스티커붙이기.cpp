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

int N, M, K, r, c;
int board[50][50];
int sticker[20][20];

void rotate() {
    int rosticker[20][20];
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++)
            rosticker[j][r-1-i] = sticker[i][j];
    }

    swap(r, c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++)
            sticker[i][j] = rosticker[i][j];
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    while (K--) {

        scanf("%d %d", &r, &c);
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++)
                scanf("%d", &sticker[i][j]);
        }

        bool complete = false;
        for (int dir=0; dir<4; dir++) { //4개의 방향
       
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) { //노트북에서 시작점 i, j
                    if (i+r > N || j+c > M) continue;
                    
                    bool check = true;
                    for (int k=0; k<r; k++) {
                        for (int l=0; l<c; l++) {
                            if (sticker[k][l] && board[i+k][j+l]) 
                                check = false;
                        }
                    }

                    if (check) {
                        for (int k=0; k<r; k++) {
                            for (int l=0; l<c; l++) {
                                if (sticker[k][l]) 
                                    board[i+k][j+l] = sticker[k][l];
                            } 
                        }
                        complete = true;
                        break;
                    }
                }
                if (complete) break;
            }
            if (complete) break;
            rotate(); // 오른쪽 방향으로 90도 회전
        }
     }

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) 
            if (board[i][j]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}