#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
char board[4000][7000];

void func(int x, int y, int height) {
    
    if (height == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';
        for (int i=y-2; i<=y+2; i++)
            board[x+2][i] = '*';
        return ;
    }

    func(x, y, height/2);
    func(x+height/2, y-height/2, height/2);
    func(x+height/2, y+height/2, height/2);
    return ;
}

int main() {

    scanf("%d", &N);
    memset(board, ' ', sizeof(board));

    int width = N*2-1;
    func(0, width/2, N); 
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<width; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
    return 0;
}

/* 재귀 문제는 절차적으로 생각하지 말고 귀납적으로 생각하자*/
/* 배열에 재귀를 이용하여 별을 찍을 수 있음*/