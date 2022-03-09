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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define INF 1000000

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int M, N;
map<ii, int> node;
vector<int> dist(10005, INF);
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<vector<ii>> graph(10005, vector<ii>(0));
vector<vector<int>> board(105, vector<int>(105, 0));


void setInput() {
    
    for (int i=1; i<=N; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=M; j++) 
            board[i][j] = s[j-1]-'0';
    }

    int idx = 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++)
            node.insert({{i, j}, idx++});
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            for (int k=0; k<4; k++) {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                graph[node[{i, j}]].push_back({node[{nx, ny}], board[nx][ny]});
            }
        }
    }
}

void Dijkstra(int st) {

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {

        ii cur = pq.top();
        pq.pop();

        if (dist[cur.Y] == cur.X) {
            for (int i=0; i<graph[cur.Y].size(); i++) {
                int next = graph[cur.Y][i].X;
                if (dist[next] > dist[cur.Y]+graph[cur.Y][i].Y) {
                    dist[next] = dist[cur.Y]+graph[cur.Y][i].Y;
                    pq.push({dist[next], next});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> M >> N;
    setInput();
    Dijkstra(1);
    cout<<dist[N*M];
    return 0;
}