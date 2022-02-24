#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int N, M;
char maze[100][100];
int dist[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main() {

    scanf("%d %d", &N, &M);
    memset(maze, '0', sizeof(maze));
    memset(dist, -1, sizeof(dist));

    for (int i=0; i<N; i++) {
        char s[105];
        scanf("%s", s);
        string str(s);
        for (int j=0; j<M; j++)
            maze[i][j] = str[j];
    }

    queue<ii> q;
    q.push({0,0});
    dist[0][0] = 0;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (maze[nx][ny] == '0' || dist[nx][ny] != -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }

    printf("%d", dist[N-1][M-1]+1);
    return 0;
}

/*시작점으로부터의 최단거리 문제*/