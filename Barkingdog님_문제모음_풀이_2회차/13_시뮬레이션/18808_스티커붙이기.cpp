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

int N, M, R, C, K, ret;
int board[45][45];
int sticker[15][15];
int tmp[15][15];


bool check(int sx, int sy) {

    for (int x=0; x<R; x++) {
        for (int y=0; y<C; y++) {
            if (x+sx < 0 || x+sx >= N || y+sy < 0 || y+sy >=M) return false;
            if (board[x+sx][y+sy] && sticker[x][y]) return false;
        }
    }
    return true;
}

ii getStart() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (check(i, j)) return {i, j};
        }
    }
    return {-1, -1};
}

void rotate() {

    for (int x=0; x<C; x++) {
        for (int y=0; y<R; y++)
            tmp[x][y] = sticker[R-1-y][x];
    }
    swap(R, C);
    for (int x=0; x<R; x++) {
        for (int y=0; y<C; y++) sticker[x][y] = tmp[x][y];
    }
}

int main() {

    cin >> N >> M >> K;
    while (K--) {

        cin >> R >> C;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) cin >> sticker[i][j];
        }

        for (int i=0; i<4; i++) {
            if (i != 0) rotate();
            ii start = getStart();
            if (start.X == -1) continue;
            for (int x=0; x<R; x++) {
                for (int y=0; y<C; y++) 
                    board[x+start.X][y+start.Y] += sticker[x][y];
            }
            break;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) ret += board[i][j];
    }
    cout<<ret;
    return 0;
}