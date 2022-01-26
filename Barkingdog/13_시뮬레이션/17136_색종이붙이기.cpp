#include <cstdio>
#include <cstring>
#include <climits>
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

int board1[10][10];
int board2[10][10];
int npaper[6] = {0, 5, 5, 5, 5, 5};
int mn = 100;


void func(int k) {

    if (k == 100) {
        int cnt = 0;
        for (int i=1; i<=5; i++) 
            cnt += (5-npaper[i]);
        mn = min(mn, cnt);
        return ;
    }

    int tmp[10][10];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++)
            tmp[i][j] = board2[i][j];
    }

    int x = k/10, y = k%10;
    if (!board1[x][y] || board2[x][y]) {
        func(k+1);
        return ;
    }

    for (int p=1; p<=5; p++) {
        if (!npaper[p]) continue;

        bool check = true;
        for (int i=x; i<x+p; i++) {
            for (int j=y; j<y+p; j++) {
                if (i>=0 && i<10 && j>=0 && j<10 && board1[i][j] && !board2[i][j]) continue;
                check = false;
                break;
            }
        }

        if (!check) continue;

        for (int i=x; i<x+p; i++) {
            for (int j=y; j<y+p; j++)
                board2[i][j] = p;
        }
        npaper[p]--;
        func(k+1);

        npaper[p]++;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++)
                board2[i][j] = tmp[i][j];
        }
    }
}


int main() {

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++)
            scanf("%d", &board1[i][j]);
    }

    func(0);
    if (mn == 100) mn = -1;
    printf("%d", mn);
    return 0;
}