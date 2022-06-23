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

int N, M;
int board[105][105];

bool OOB(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

bool checkTwoside(vector<vector<bool>>& air, int x, int y) {
    
    int cnt = 0;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (OOB(nx, ny) || !air[nx][ny]) continue;
        cnt++;
    }
    return cnt >= 2;
}

int melt() {

    vector<vector<bool>> air(105, vector<bool>(105, false));

    queue<ii> q;
    q.push({0, 0});
    air[0][0] = true;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (OOB(nx, ny) || board[nx][ny] || air[nx][ny]) continue;
            q.push({nx, ny});
            air[nx][ny] = true;
        }
    }

    vector<vector<bool>> del(105, vector<bool>(105, false));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!board[i][j]) continue;
            if (!checkTwoside(air, i, j)) continue;
            del[i][j] = true;
        }
    }

    int cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!del[i][j]) continue;
            board[i][j] = 0;
            cnt++;
        }
    }
    return cnt;
}


int main() {
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) cin >> board[i][j];
    }
    
    int t = 0;
    while (true) {
        if (melt()) t++;
        else break;
    }
    
    cout<<t;
    return 0;
}