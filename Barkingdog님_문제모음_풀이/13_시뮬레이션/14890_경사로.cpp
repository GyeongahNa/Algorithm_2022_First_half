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

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int N, L;
int board[110][110];
int re;

bool checkLine(int isrow, int n) {

    int cnt = 1, down = 0;
    for (int idx=1; idx<N; idx++) {

        int i = isrow ? n : idx;
        int j = isrow ? idx : n;
        int before = isrow ? board[i][j-1] : board[i-1][j];

        if (board[i][j] == before) cnt++;
        else if (board[i][j] == before+1) {
            if (cnt < (down+1)*L) return false;
            down = 0; cnt = 1;
        }
        else if (board[i][j] == before-1) {
            if (cnt < down*L) return false;
            down = 1; cnt = 1;
        }
        else return false;
    }
    if (down && cnt < L) return false; 
    return true;
}

int main() {

    scanf("%d %d", &N, &L);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }

    for (int i=0; i<N; i++) {
        if (checkLine(1, i)) re++;
        if (checkLine(0, i)) re++;
    }

    printf("%d", re);
    return 0;
}