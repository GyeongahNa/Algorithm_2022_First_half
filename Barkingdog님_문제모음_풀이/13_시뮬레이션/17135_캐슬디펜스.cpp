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

int N, M, D;
int board[20][20];
int arr[3];
int mx = 0;


bool allDead(int tmp[20][20]) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tmp[i][j]) return false;
        }
    }
    return true;
}


void kill(int tmp[20][20], int &cnt) {
    
    ii enemy[3] = {};
    for (int i=0; i<3; i++) {

        int ndist = 100000, nx = -1, ny = -1;

        for (int j=0; j<M; j++) {
            for (int k=N-1; k>=0; k--) {
                if (!tmp[k][j]) continue;
                int dist = abs(N-k)+abs(arr[i]-j);
                if (dist > D || dist >= ndist) continue;
                ndist = dist, nx = k, ny = j;
            }
        }
        enemy[i] = {nx, ny};
    }

    for (int i=0; i<3; i++) {
        if (enemy[i].X ==- 1 || enemy[i].Y == -1) continue;
        if (!tmp[enemy[i].X][enemy[i].Y]) continue;
        tmp[enemy[i].X][enemy[i].Y] = 0;
        cnt++;
    }
}


void pullDown(int tmp[20][20]) {

    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<M; j++) {
            if (i == 0) tmp[i][j] = 0;
            else tmp[i][j] = tmp[i-1][j];
        }
    }
}


void getMaxCnt() {

    int tmp[20][20];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            tmp[i][j] = board[i][j];
    }

    int cnt = 0;
    while (!allDead(tmp)) {
        kill(tmp, cnt);
        pullDown(tmp);
    }

    mx = max(mx, cnt);
}


void func(int k) {

    if (k == 3) {
        getMaxCnt();
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<M; i++) {
        arr[k] = i;
        func(k+1);
    }
}


int main() {

    scanf("%d %d %d", &N, &M, &D);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            scanf("%d", &board[i][j]);
    }

    func(0);
    printf("%d", mx);
    return 0;
}