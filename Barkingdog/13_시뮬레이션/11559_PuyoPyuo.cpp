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

char field[12][6];
int visited[12][6];
bool check;
int total;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int& npop) {

    queue<ii> q, rec;
    q.push({x, y});
    rec.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (field[nx][ny] != field[cur.X][cur.Y] || visited[nx][ny]) continue;   
            q.push({nx, ny});
            rec.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    if (rec.size() >= 4) {
        while (!rec.empty()) {
            ii front = rec.front();
            field[front.X][front.Y] = '.';
            rec.pop();
        }
        npop++;
    }
}

void pop() {

    memset(visited, 0, sizeof(visited));

    int npop = 0;
    for (int i=0; i<12; i++) {
        for (int j=0; j<6; j++) {
            if (field[i][j] == '.') continue;
            bfs(i, j, npop);
        }
    }

    if (npop == 0) check = false;
    else total++;
}

void tofloor(int x, int y) {

    char tmp = field[x][y];
    field[x][y] = '.';

    while (1) {
        x += 1;
        if (x >= 12 || field[x][y] != '.') {
            field[x-1][y] = tmp;
            return ;
        }
    }
}

void toDown() {

    for (int i=11; i>=0; i--) {
        for (int j=0; j<6; j++) {
            if (field[i][j] == '.') continue;
                tofloor(i, j);
        }
    }
}

int main() {

    for (int i=0; i<12; i++) {
        for (int j=0; j<6; j++)
            scanf(" %c", &field[i][j]);
    }

    check = true;
    while (check) {
        pop();
        toDown();
    }
    printf("%d", total);
    return 0;
}