#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int board[20][20];
int re;

vector<int> mv[3] = {{0, 2}, {1, 2}, {0, 1, 2}};
vector<int> dx[3] = {{0}, {1}, {0, 1, 1}};
vector<int> dy[3] = {{1}, {0}, {1, 0, 1}};


bool OOB(int x, int y) {
    return x < 1 || x > N || y < 1 || y > N;
}


void bfs(int sx, int sy, int sd) {

    queue<iii> q;
    q.push({sx, sy, sd});

    while (!q.empty()) {

        iii cur = q.front();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int d = get<2>(cur);
        q.pop() ;

        if (x == N && y == N) re++;

        for (int i=0; i<mv[d].size(); i++) {

            bool check = true;
            for (int j=0; j<dx[mv[d][i]].size(); j++) {
                int nx = x+dx[mv[d][i]][j];
                int ny = y+dy[mv[d][i]][j];
                if (!OOB(nx, ny) && !board[nx][ny]) continue;
                check = false;
                break;
            }

            if (!check) continue;
            if (mv[d][i] == 0) q.push({x, y+1, 0});
            else if (mv[d][i] == 1) q.push({x+1, y, 1});
            else q.push({x+1, y+1, 2});
        }
    }
}


int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++)
            scanf("%d", &board[i][j]);
    }

    bfs(1, 2, 0);
    printf("%d", re);
    return 0;
}