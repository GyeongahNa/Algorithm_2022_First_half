#include <cstdio>
#include <cstring>
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

int R, C, K, cnt;
int board[10][10];
bool visited[10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void getInput() {

    for (int i=0; i<R; i++) {
        string s;
        cin >> s;
        for (int j=0; j<C; j++)
            board[i][j] = ((s[j] == 'T') ? 1 : 0);
    }
}

void dfs(int x, int y, int k) {

    if (k == 1) {
        if (x == 0 && y == C-1) cnt++;
        return ;
    }

    visited[x][y] = true;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] || board[nx][ny]) continue;
        dfs(nx, ny, k-1);
    }
    visited[x][y] = false;
}


int main() {

    cin >> R >> C >> K;
    getInput();
    dfs(R-1, 0, K);
    cout<<cnt;
    return 0;
}