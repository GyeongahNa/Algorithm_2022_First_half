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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cnt;
char board[20][10];

char notErase(char c) { return c; }
char Erase(char c) { return '.'; }

int bfs(int x, int y, char (*action)(char c)) {

    vector<vector<bool>> check(20, vector<bool>(10, false));

    int cnt = 0;
    queue<ii> q;
    q.push({x, y});
    check[x][y] = true;
    char color = board[x][y];

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();
        cnt++;
        board[cur.X][cur.Y] = action(board[cur.X][cur.Y]);

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (check[nx][ny] || board[nx][ny] != color) continue;
            q.push({nx, ny});
            check[nx][ny] = true;
        }
    }
    return cnt;
}

int pop() {

    int npop = 0;
    for (int i=0; i<12; i++) {
        for (int j=0; j<6; j++) {
            if (board[i][j] == '.') continue;
            int cnt = bfs(i, j, notErase);
            if (cnt >= 4) {
                npop += cnt;
                bfs(i, j, Erase);
            }
        }
    }
    return npop;
}

void moveDown() {

    for (int i=11; i>=0; i--) {
        for (int j=0; j<6; j++) {
            if (board[i][j] == '.') continue;

            int x = i, y = j;
            while (1) { 
                x += 1;
                if (x >= 12 || board[x][y] != '.') break;
            }
            
            char tmp = board[i][j];
            board[i][j] = '.';
            board[x-1][y] = tmp;
        }
    }
}

int main() {

    for (int i=0; i<12; i++) {
        string s;
        cin >> s;
        for (int j=0; j<6; j++) board[i][j] = s[j];
    }

    while (1) {
        int status = pop();
        if (!status) break;
        cnt++;
        moveDown();
    }
    cout<<cnt;
    return 0;
}