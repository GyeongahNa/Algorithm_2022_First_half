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
#define MX 2147483640

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int board[55][55];
int N, L, R;

int main() {

    scanf("%d %d %d", &N, &L, &R);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }

    int day = 0;
    while (1) {

        int num = 0;
        int visited[55][55];
        memset(visited, 0, sizeof(visited));

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j]) continue;

                int cnt = 0, sum = 0;
                queue<ii> q;
                q.push({i, j});
                visited[i][j] = 1;
                
                vector<ii> v;
                while (!q.empty()) {
                    
                    ii cur = q.front();
                    q.pop();
                    cnt++;
                    sum += board[cur.X][cur.Y];
                    v.push_back({cur.X, cur.Y});

                    for (int i=0; i<4; i++) {
                        int nx = cur.X+dx[i];
                        int ny = cur.Y+dy[i];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (visited[nx][ny]) continue;
                        int diff = abs(board[cur.X][cur.Y]-board[nx][ny]);
                        if (diff < L || diff > R) continue;
                        
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
        
                    }
                }

                if (cnt < 2) continue;
                for (int k=0; k<v.size(); k++)
                    board[v[k].X][v[k].Y] = sum/cnt;
                num++;
            }   
        }

        if (!num) break;
        day++;
    }
    printf("%d", day);
    return 0;
}