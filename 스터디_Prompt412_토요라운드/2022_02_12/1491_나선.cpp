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

int dx[4] = {0, 1, 0,  -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int board[5005][5005];
bool visited[5005][5005];


bool OOB(int x,  int y) {
    return x < 0 || x >= M || y < 0 || y >= N;
}

int main() {

    scanf("%d %d", &N, &M);

    int x = 0, y = 0, d = 0, cnt=0;
    visited[x][y] = true;

    int idx = 1;
    while (cnt < 2) {

        int nx = x+dx[d];
        int ny = y+dy[d];
        
        if (OOB(nx, ny) || visited[nx][ny]) {
            d = (d+1)%4;
            cnt++;
            continue;
        }
        x = nx; 
        y = ny;
        visited[x][y] = true;
        cnt = 0;
    }

    printf("%d %d", y, x);
    return 0;
}