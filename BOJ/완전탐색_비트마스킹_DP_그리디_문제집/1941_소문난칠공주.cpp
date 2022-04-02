#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, re;
int arr[10];
char board[10][10];
bool check[10][10];


bool connected(int st) {

    queue<ii> q;
    bool visited[10][10] = {};

    q.push({st/5, st%5});
    visited[st/5][st%5] = true;

    while (!q.empty()) {

        ii cur = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || !check[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    for (int i=1; i<7; i++) {
        int n = arr[i];
        int x = n/5, y = n%5;
        if (visited[x][y]) continue;
        return false;
    }
    return true;
}


void backTracking(int k, int nLee) {

    if (k == 7) {
        if (nLee < 4 || !connected(arr[0])) return;
        re++;
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<25; i++) {
        arr[k] = i;
        int x = i/5, y = i%5;
        check[x][y] = true;
        backTracking(k+1, nLee+(board[x][y] == 'S'));
        check[x][y] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    N = 5;
    for (int i =0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> board[i][j];
    }

    backTracking(0, 0);
    cout<<re;
    return 0;
}