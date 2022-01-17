#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int N;
int board[110][110];
int re;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void cnt() {

    for (int i=0; i<=100; i++) {
        for (int j=0; j<=100; j++) {
            if (i+1 > 100 || j+1 > 100) continue;
            if (!board[i][j] || !board[i][j+1] || !board[i+1][j] || !board[i+1][j+1]) continue;
            re++;
        }
    }
}

void draw(int x, int y, int d,  int g) {

    vector<int> v;
    v.push_back(d);
    board[x][y] = 1;

    while (g--) {
        int vsize = v.size();
        for (int i=v.size()-1; i>=0; i--)
            v.push_back((v[i]+1)%4);
    }

    for (int i=0; i<v.size(); i++) {
        x += dx[v[i]];
        y += dy[v[i]];
        board[x][y] = 1;
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x, y, d, g;
        scanf("%d %d %d %d", &y, &x, &d, &g);
        draw(x, y, d, g);
    }   
    cnt();
    printf("%d", re);
    return 0;
}