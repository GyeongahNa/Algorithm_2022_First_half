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

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int N, M, K;
ii smell[25][25]; //(상어번호, 지속시간)
iii shark[500]; // (x, y, d)
int prior[500][5][4]; // [상어번호][방향][우선순위]


void removeSmell() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!smell[i][j].X) continue;
            smell[i][j].Y -= 1;
            if (!smell[i][j].Y) smell[i][j].X = 0;
        }
    }
}

void moveShark() {

    vector<int> tmp[25][25] = {};

    for (int i=1; i<=M; i++) {
        
        int x = get<0>(shark[i]);
        int y = get<1>(shark[i]);
        int d = get<2>(shark[i]);
        if (x == -1 || y == -1) continue;
        
        // 아무 냄새 없는 칸
        int check = 0;
        for (int j=0; j<4; j++) {
            int nx = x+dx[prior[i][d][j]];
            int ny = y+dy[prior[i][d][j]];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (smell[nx][ny].X) continue;
            tmp[nx][ny].push_back(i);
            shark[i] = {nx, ny, prior[i][d][j]};
            check = 1;
            break;
        }

        // 자신의 냄새가 있는 칸
        if (!check) {
            for (int j=0; j<4; j++) {
                int nx = x+dx[prior[i][d][j]];
                int ny = y+dy[prior[i][d][j]];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (smell[nx][ny].X != i) continue;
                tmp[nx][ny].push_back(i);
                shark[i] = {nx, ny, prior[i][d][j]};
                break;
            }
        }
    }

    removeSmell();
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!tmp[i][j].size()) continue;
            sort(tmp[i][j].begin(), tmp[i][j].end());
            smell[i][j] = {tmp[i][j][0], K};
            for (int k=1; k<tmp[i][j].size(); k++)
                shark[tmp[i][j][k]] = {-1, -1, -1};
         }
    }
}

bool check() {
    
    for (int i=2; i<=M; i++) {
        if (get<0>(shark[i]) != -1 || get<1>(shark[i]) != -1) return false;
    }
    return true;
}

int main () {

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int x;
            scanf("%d", &x);
            if (!x) continue;
            smell[i][j] = {x, K};
            shark[x] = {i, j, -1};
        }
    }

    for (int i=1; i<=M; i++) {
        int d;
        scanf("%d", &d);
        get<2>(shark[i]) = d;
    }

    for (int i=1; i<=M; i++) {
        for (int j=1; j<=4; j++) {
            for (int k=0; k<4; k++)
                scanf("%d", &prior[i][j][k]);
        }
    }

    int t = 1;
    while (t <= 1000) {
        moveShark();       
        if (check()) break;
        t++;

    }

    if (t >= 1001) printf("-1");
    else printf("%d", t);
    return 0;
}