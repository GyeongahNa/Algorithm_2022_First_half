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

#define X first
#define Y second

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N, M, x, y, K, d, nx, ny;
int dice[7];
int board[25][25];

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

void moveDice(int d) {

    vector<int> newDice(7, 0), tmp(7, 0);

    if (d == 1) tmp = {0, 1, 5, 3, 6, 4, 2};
    else if (d == 2) tmp = {0, 1, 6, 3, 5, 2, 4};
    else if (d == 3) tmp = {0, 2, 3, 4, 1, 5, 6};
    else tmp = {0, 4, 1, 2, 3, 5, 6};

    for (int i=1; i<=6; i++) newDice[i] = dice[tmp[i]];
    for (int i=1; i<=6; i++) dice[i] = newDice[i];
}

int main() {

    cin >> N >> M >> x >> y >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> board[i][j];
    }

    while (K--) {
        cin >> d;
        nx = x+dx[d-1]; ny = y+dy[d-1];
        if (OOB(nx, ny)) continue;
        
        x = nx; y = ny;
        moveDice(d);

        if (!board[x][y]) board[x][y] = dice[4];
        else {
            dice[4] = board[x][y];
            board[x][y] = 0;
        }
        cout<<dice[2]<<"\n";
    }
    return 0;
}