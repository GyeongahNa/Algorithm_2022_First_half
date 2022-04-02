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

int cnt;
int arr[10];
char board[10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(const vector<vector<int>>& tmp) {

    vector<vector<int>> check(5, vector<int>(5, 0));

    int cntLee = 0;
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (!tmp[i][j]) continue;

            queue<ii> q;
            q.push({i, j});
            check[i][j] = true;

            while (!q.empty()) {

                ii cur = q.front();
                if (board[cur.X][cur.Y] == 'S') cntLee++;
                q.pop();

                for (int k=0; k<4; k++) {
                    int nx = cur.X+dx[k];
                    int ny = cur.Y+dy[k];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (!tmp[nx][ny] || check[nx][ny]) continue;
                    q.push({nx, ny});
                    check[nx][ny] = true;
                }
            }
            
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    if (tmp[i][j] && !check[i][j]) return -1;
                }
            }
            return cntLee;
        }
    }
    return cntLee;
}

void combination(int k) {

    if (k == 7) {
        vector<vector<int>> tmp(5, vector<int>(5, 0));
        for (int i=0; i<7; i++) tmp[arr[i]/5][arr[i]%5] = 1;
        int nLee = bfs(tmp);
        if (nLee != -1 && nLee > 7-nLee) cnt++;
        return ;
    }

    int st = 0;
    if (k!=0) st = arr[k-1]+1;
    for (int i=st; i<25; i++) {
        arr[k] = i;
        combination(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) cin >> board[i][j];
    }
    combination(0);
    cout<<cnt;
    return 0;
}