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
using iii = tuple<int, int, int>;

#define X first
#define Y second

int L, R, C;
char b[30][30][30];
int dist[30][30][30];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {

    while (true) {
        scanf("%d %d %d", &L, &R, &C);
        
        if (L == 0 || R == 0 || C == 0) break;

        memset(b, '0', sizeof(b));
        memset(dist, -1, sizeof(dist));

        queue<iii> q;
        int ei = -1, ej = -1, ek = -1;
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                for (int k=0; k<C; k++) {
                    scanf(" %c", &b[i][j][k]);
                    if (b[i][j][k] == 'S') {
                        q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    else if (b[i][j][k] == 'E') {
                        ei = i, ej = j, ek = k;
                    }
                }
            }
        }

        while (!q.empty()) {

            iii cur = q.front();
            q.pop();

            for (int i=0; i<6; i++) {
                int nx = get<0>(cur)+dx[i];
                int ny = get<1>(cur)+dy[i];
                int nz = get<2>(cur)+dz[i];

                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
                if (b[nx][ny][nz] == '#' || dist[nx][ny][nz] != -1) continue;

                q.push({nx, ny, nz});
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            }
        }

        int re = dist[ei][ej][ek];
        if (re == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", re);
    }
    return 0;
}