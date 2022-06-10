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

#define X first
#define Y second
#define div 1000000007

int N, M;
char board[2005][2005];
bool visited[2005][2005];
int P2[4000005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y) {

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[x][y] != board[nx][ny]) return true;
    }
    return false;
}

ii bfs(int x, int y) {

    queue<ii> q;
    q.push({x, y});
    visited[x][y] = true;

    ii ret = {0, 0};
    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        ret.X++;
        if (check(cur.X, cur.Y)) ret.Y++;

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny] || board[x][y] != board[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) board[i][j] = s[j];
    }

    P2[0] = 1;
    for (int i=1; i<=4000000; i++) P2[i] = P2[i-1]*2%div;

    long long ans = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visited[i][j]) continue;
            ii cnt = bfs(i, j);
            ans = ans*P2[cnt.X-cnt.Y]%div;
        }
    }

    cout<<ans;
    return 0;
}