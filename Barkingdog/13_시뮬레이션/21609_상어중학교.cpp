#include <cstdio>
#include <cstring>
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

int N, M, score;
int board[25][25];
bool visited[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


vector<vector<int>> findGroups() {

    vector<vector<int>> vgroups;
    memset(visited, false, sizeof(visited));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] <= 0 || visited[i][j]) continue;

            int num = board[i][j];

            queue<ii> q;
            q.push({i, j});
            visited[i][j] = true;

            int cntB = 0, cntR = 0;
            while (!q.empty()) {

                ii cur = q.front();
                q.pop();
                cntB++;

                for (int k=0; k<4; k++) {
                    int nx = cur.X+dx[k];
                    int ny = cur.Y+dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] < 0 || visited[nx][ny]) continue;
                    if (board[nx][ny] && board[nx][ny] != num) continue;
                    if (!board[nx][ny]) cntR++;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }

            vector<int> grp = {cntB, cntR, i, j};
            if (cntB >= 2) vgroups.push_back(grp);

            for (int k=0; k<N; k++) {
                for (int l=0; l<N; l++) {
                    if (board[k][l]) continue;
                    visited[k][l] = false;
                }
            }
        }
    }

    sort(vgroups.begin(), vgroups.end(), greater<>());
    return vgroups;
}


void removeLargest(vector<int> largest) {

    int tmp[25][25];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            tmp[i][j] = board[i][j];
    }

    queue<ii> q;
    q.push({largest[2], largest[3]});
    memset(visited, false, sizeof(visited));
    visited[largest[2]][largest[3]] = true;
    
    int num = board[largest[2]][largest[3]];

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();
        tmp[cur.X][cur.Y] = -2;

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] < 0 || visited[nx][ny]) continue;
            if (board[nx][ny] && board[nx][ny] != num) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }       
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            board[i][j] = tmp[i][j];
    }
}


void makeGravity() {

    for (int i=N-2; i>=0; i--) {
        for (int j=0; j<N; j++) {
            if (board[i][j] <= -1) continue;

            int x = i;
            while (1) {
                int nx = x+1;
                if (nx >= N || board[nx][j] != -2) break; 
                x = nx;
            }

            int tmp = board[i][j];
            board[i][j] = -2;
            board[x][j] = tmp;
        }
    }
}


void rotate() {

    int tmp[25][25];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            tmp[i][j] = board[j][N-1-i];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            board[i][j] = tmp[i][j];
    }
}


int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }

    while (1) {

        vector<vector<int>> vgroups = findGroups();
        if (vgroups.empty()) break;

        score += vgroups[0][0]*vgroups[0][0];
        removeLargest(vgroups[0]);
        makeGravity();
        rotate();
        makeGravity();
    }
    printf("%d", score);
    return 0;
}

/* 기준 블록에서 시작하여 bfs를 수행한 이후, 
다음 턴에서도 무지개 블록을 사용할 수 있으므로 무지개 블록의 visited[][] 값은 다시 false로 바꾸어주어야 함*/