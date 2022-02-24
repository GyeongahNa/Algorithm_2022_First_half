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
#define MX 2147483647

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, L; 
int board[25][25];
int x, y;

vector<vector<ii>> p;

ii findNearest() {

    //가장 가까운 고객 찾기
    int dist[25][25];
    memset(dist, -1, sizeof(dist));

    queue<ii> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        
        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] || dist[nx][ny] != -1) continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }

    int person = -1, mn = MX;
    for (int i=0; i<M; i++) {
        if (p[i][0].X == -1) continue;
        int d = dist[p[i][0].X][p[i][0].Y];
        if (d == -1) continue;
        if (d >= mn) continue;
        person = i;
        mn = d;
    }

    return {person, mn};
}

int getDist(int person) {

    int sx = p[person][0].X;
    int sy = p[person][0].Y;
    int ex = p[person][1].X;
    int ey = p[person][1].Y;

    int dist[25][25];
    memset(dist, -1, sizeof(dist));

    queue<ii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        if (cur.X == ex && cur.Y == ey) return dist[ex][ey];

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] || dist[nx][ny] != -1) continue;

            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
    return -1;
}

bool move() {

    ii nearst = findNearest(); //(고객, 거리)
    int np = nearst.X;
    int taxiToP = nearst.Y;
    if (np == -1) return false;

    int pToEnd = getDist(np);
    if (pToEnd == -1 || L-taxiToP-pToEnd < 0) return false;

    x = p[np][1].X;
    y = p[np][1].Y;
    L = L-taxiToP-pToEnd+2*pToEnd;
    p[np][0].X = -1;
    return true;
}

int main() {

    scanf("%d %d %d", &N, &M, &L);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }

    scanf("%d %d", &x, &y);
    --x; --y;
    for (int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        p.push_back({{--x1, --y1}, {--x2, --y2}});
    }
    sort(p.begin(), p.end());

    for (int i=0; i<M; i++) {
        if (!move()) {
            L = -1;
            break;
        }
    }
    printf("%d", L);
    return 0;
}

/*ny를 nx로 써서 5트를 했다*/
/*정말 사소한 실수만 줄인다면 디버깅 시간 없앨 수 있을 텐데...!*/