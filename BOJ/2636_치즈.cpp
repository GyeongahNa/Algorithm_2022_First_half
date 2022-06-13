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
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

#define X first
#define Y second

int N, M;
int board[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool ismelted(int x, int y, const vvb& visited) {
    
    if (!board[x][y]) return false;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (!visited[nx][ny]) continue;
        return true;
    }
    return false;
}

int bfs() {
    
   vvb visited(105, vb(105, false));
    
    queue<ii> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        
        ii cur = q.front();
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny] || board[nx][ny]) continue;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!ismelted(i, j, visited)) continue;
            board[i][j] = 0;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> board[i][j];
    }
    
    int niter = 0, nmelted = 0, bfmelted = 0;
    while (true) {
        nmelted = bfs();
        if (!nmelted) break;
        niter++;
        bfmelted = nmelted;
    }
    
    cout<<niter<<'\n';
    cout<<bfmelted<<'\n';
    return 0;
}