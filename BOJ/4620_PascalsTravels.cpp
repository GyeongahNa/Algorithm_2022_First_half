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

string s;
int N, cnt;
int board[40][40];
long long dp[40][40];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

long long getCnt(int x, int y) {

    if (x == N && y == N) return dp[x][y] = 1;
    if (!board[x][y]) return 0;
    if (dp[x][y]) return dp[x][y];

    for (int i=0; i<2; i++) {
        int nx = x+dx[i]*board[x][y];
        int ny = y+dy[i]*board[x][y];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        dp[x][y] += getCnt(nx, ny);
    }

    return dp[x][y];
}

int main() {

    while (true) {
        cin >> N;
        if (N == -1) break;
        for (int i=1; i<=N; i++) {
            cin >> s;
            for (int j=1; j<=N; j++) {
                dp[i][j] = 0;
                board[i][j] = s[j-1]-'0';
            }
        }
        cout<<getCnt(1,1)<<"\n";
    }
    return 0;   
}