#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, N, h, mn;
char board[105][105];
bool visited[105][105];

bool OOB(int x, int y) {
    return x < 0 || x > R || y < 0 || y >= C;
}

void getBoard() {
   
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) cin >> board[i][j];
    }
    for (int j=0; j<C; j++) board[R][j] = 'x';
}

int getCrashPoint(int h, int idx) {
    
    if (idx%2 == 0) {
        int j =0;
        while (j < C && board[R-h][j] == '.') j++;
        return j;
    }
    
    int j = C-1;
    while (j >= 0 && board[R-h][j] == '.') j--;
    return j;
}

bool destroy(int h, int idx) {
    
    int j = getCrashPoint(h, idx);
    if (OOB(R-h, j)) return false;
    board[R-h][j] = '.';
    return true;
}

void checkCluster() {
    
    for (int i=0; i<105; i++) {
        for (int j=0; j<105; j++) visited[i][j] = false;
    }
    
    queue<ii> q;
    q.push({R, 0});
    visited[R][0]  = true;
    
    while (!q.empty()) {
        
        ii cur = q.front();
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (OOB(nx, ny) || visited[nx][ny] || board[nx][ny] != 'x') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void getMinHeight() {
    
    mn = R;
    for (int j=0; j<C; j++) {

        int pc = -1;
        for (int i=0; i<R; i++) {
            if (board[i][j] == 'x' && !visited[i][j]) pc = max(pc, i);
        }

        int pm = R;
        for (int i=R-1; i>=0; i--) {
            if (board[i][j] == 'x' && !visited[i][j]) break;
            if (board[i][j] == 'x' && visited[i][j]) pm = min(pm, i);
        }

        if (pc != -1) mn = min(mn, pm-pc-1);
    }
}

void moveCluster() {
    
    for (int j=0; j<C; j++) {
        for (int i=R-1; i>=0; i--) {
            if (board[i][j] == '.' || visited[i][j]) continue;
            board[i][j] = '.';
            board[i+mn][j] = 'x';
        }
    }
}

void getDownCluster() {
    
    checkCluster();
    getMinHeight();
    moveCluster();
}

void printboard() {
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) cout<<board[i][j];
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> R >> C;
    getBoard();
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> h;
        if (!destroy(h, i)) continue;
        getDownCluster();
    }
    
    printboard();
    return 0;
}