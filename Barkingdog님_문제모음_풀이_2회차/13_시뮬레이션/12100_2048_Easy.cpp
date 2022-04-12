#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, ret;
vector<vector<int>> board(25, vector<int>(25, 0));


bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N;
}


void step(vector<vector<int>>& cpy, vector<vector<bool>>& check, int i, int j, int d) {

    int x = i, y = j;
    while (1) {
        x += dx[d]; y += dy[d];
        if (OOB(x, y) || cpy[x][y]) break;
    }

    if (!OOB(x, y) && cpy[x][y] == cpy[i][j] && !check[x][y]) {
        int tmp = 2*cpy[x][y];
        cpy[i][j] = 0;
        cpy[x][y] = tmp;
        check[x][y] = true;
    }
    else {
        x -= dx[d];
        y -= dy[d];
        int tmp = cpy[i][j];
        cpy[i][j] = 0;
        cpy[x][y] = tmp;
    }
}


void move(vector<vector<int>>& cpy, int d) {

    vector<vector<bool>> check(25, vector<bool>(25, false));

    if (d == 0 || d == 3) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!cpy[i][j]) continue;
                step(cpy, check, i, j, d);
            }
        }
        return ;
    }

    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>=0; j--) {
            if (!cpy[i][j]) continue;
            step(cpy, check, i, j, d);
        }
    }
}


int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cin >> board[i][j];
    }

    for (int i=0; i<(1<<10); i++) {

        vector<vector<int>> cpy(25, vector<int>(25, 0));
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++)
                cpy[j][k] = board[j][k];
        }

        int tmp = i;
        for (int j=0; j<5; j++) {
            int d = tmp%4;
            tmp /= 4;
            move(cpy, d);
        }

        int mx = 0;
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++)
                mx = max(cpy[j][k], mx);
        }
        ret = max(ret, mx);
    }
    cout<<ret;
    return 0;
}