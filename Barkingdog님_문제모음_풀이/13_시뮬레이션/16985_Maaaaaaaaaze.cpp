#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int maze1[5][5][5];
int maze2[5][5][5];
int arr[5];
int isused[5];
int mn = MX;

int dz[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};

int getPow(int n, int k) {

    int re = 1;
    for (int i=0; i<k; i++)
        re *= n;
    return re;
}

void roate(int n, int dir) {

    for (int i=0; i<dir; i++) {
        int tmp[5][5];
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++)
                tmp[k][4-j] = maze2[n][j][k];
        }
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++)
                maze2[n][j][k] = tmp[j][k];
        }
    }
}

void setMaze(int n, int dir) {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++)
            maze2[n][i][j] = maze1[arr[n]][i][j];
    }
    roate(n, dir);
}

void bfs() {

    int dist[5][5][5];
    memset(dist, -1, sizeof(dist));

    queue<iii> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {
        iii cur = q.front();
        int z, x, y;
        tie(z, x, y) = cur;
        q.pop();

        for (int i=0; i<6; i++) {

            int nz = z+dz[i];
            int nx = x+dx[i];
            int ny = y+dy[i];

            if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (!maze2[nz][nx][ny] || dist[nz][nx][ny] != -1) continue;
            q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[z][x][y]+1;
        }
    }

    int re = dist[4][4][4];
    if (re != -1) mn = min(re, mn);
}

void func(int k) { 

    if (k == 5) {
        int nrotate = getPow(4, 5);
        for (int r=0; r<nrotate; r++) {
            int tmp = r;
            for (int i=0; i<5; i++) {
                int dir = tmp%4;
                tmp /= 4;
                setMaze(i, dir);
            }
            if (!maze2[0][0][0] || !maze2[4][4][4]) continue;
            bfs(); 
        }
        return ;
    }

    for (int i=0; i<5; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}


int main() {

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++)
                scanf("%d", &maze1[i][j][k]);
        }
    }

    func(0);
    if (mn == MX) printf("-1");
    else printf("%d", mn);
    return 0;
}