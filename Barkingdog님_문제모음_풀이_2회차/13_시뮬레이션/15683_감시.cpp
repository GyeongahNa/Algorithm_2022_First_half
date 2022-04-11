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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int mn = INT_MAX;
vector<ii> pos;
vector<int> cctv;
vector<vector<char>> board(10, vector<char>(10, 0));
vector<vector<int>> dir = {{}, {1}, {1, 3}, {0, 1}, {0, 1, 3}, {0, 1, 2, 3}};


int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= '1' && board[i][j] <= '5') {
                pos.push_back({i, j});
                cctv.push_back(board[i][j]-'0');
            }
        }
    }

    for (int i=0; i<(1<<2*cctv.size()); i++) {

        vector<vector<char>> tmpboard(10, vector<char>(10, 0));
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) tmpboard[i][j] = board[i][j];
        }

        int tmp = i;
        for (int j=0; j<cctv.size(); j++) {
            int r = tmp%4;
            for (auto d : dir[cctv[j]]) {
                int nd = (d+r)%4;
                int x = pos[j].X;
                int y = pos[j].Y;
                while (1) {
                    x += dx[nd];
                    y += dy[nd];
                    if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '6') break;
                    if (board[x][y] == '0') tmpboard[x][y] = '#';
                }
            }
            tmp /= 4;
        }

        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (tmpboard[i][j] == '0') cnt++;
            }
        }

        mn = min(mn, cnt);
    }

    cout<<mn;
    return 0;
}