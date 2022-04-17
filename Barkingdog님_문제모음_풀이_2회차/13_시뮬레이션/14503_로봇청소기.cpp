#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, cnt;
int r, c, d;
int board[55][55];
bool visited[55][55];

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void clean(int x, int y, int dir) {

    for (int i=0; i<4; i++) {
        dir = (dir+3)%4;
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if (OOB(nx, ny) || visited[nx][ny] || board[nx][ny]) continue;
        cnt++;
        visited[nx][ny] = true;
        clean(nx, ny, dir);
        return ;
    }

    int bd = (dir+2)%4;
    int bx = x+dx[bd];
    int by = y+dy[bd];
    if (OOB(bx, by) || board[bx][by]) return ;
    clean(bx, by, dir);
}

int main() {

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> board[i][j];
    }

    cnt = 1;
    visited[r][c] = true;
    clean(r, c, d);
    cout<<cnt;
    return 0;
}