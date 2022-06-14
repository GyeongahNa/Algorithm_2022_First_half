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

int N, K, S, x, y;
int board[205][205];
priority_queue<iii, vector<iii>, greater<iii>> pq;
vector<iii> v;

void spread(int n, int a, int b) {

    for (int i=0; i<4; i++) {
        int nx = a+dx[i];
        int ny = b+dy[i];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (board[nx][ny]) continue;
        board[nx][ny] = n;
        v.push_back({n, nx, ny});
    }
}

int main() {

    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> board[i][j];
            if (board[i][j]) pq.push({board[i][j], i, j});
        }
    }
    cin >> S >> x >> y;

    while (S--) {
        while (!pq.empty()) {
            int n, a, b;
            tie(n, a, b) = pq.top();
            spread(n, a, b);
            pq.pop();
        }
        for (auto& [n, a, b] : v) pq.push({n, a, b});
        v.clear();
    }

    cout<<board[x][y];
    return 0;
}