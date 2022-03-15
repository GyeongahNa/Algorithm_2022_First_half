#include <cstdio>
#include <cstring>
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


int bfs(int x, int y, int m, int n, vector<vector<int>>& picture, vector<vector<int>> &visited) {
    
    queue<ii> q;

    //시작점 큐에 추가
    q.push({x, y});
    visited[x][y] = true;
    
    int cnt = 0;
    while (!q.empty()) {
        
        ii cur = q.front();
        q.pop();

        //영역의 넓이 1 증가
        cnt++; 
        
        for (int i=0; i<4; i++) {
            int nx = cur.X+dx[i];
            int ny = cur.Y+dy[i];

            //상하좌우 좌표 중 영역 확장 가능한 지점 탐색
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (picture[cur.X][cur.Y] != picture[nx][ny]) continue;
            if (visited[nx][ny]) continue;

            //큐에 추가 후 방문 기록 갱신
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<vector<int>> visited(m, vector<int>(n, false));
    
    int num = 0, mx = 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {

            //컬러링북에서 색칠되어있고 아직 방문하지 않은 지점을 bfs 시작점으로 설정
            if (!picture[i][j] || visited[i][j]) continue;

            //영역 개수 1 증가
            num++;

            // 영역의 넓이를 계산하여 mx(최댓값) 갱신
            mx = max(mx, bfs(i, j, m, n, picture, visited));
        }
    }
    
    vector<int> ret = {num, mx};
    return ret;
}