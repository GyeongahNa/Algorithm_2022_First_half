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
#define INF INT_MAX

int N, E, v1, v2;

vector<vector<int>> dist(805, vector<int>(805, INF));
vector<vector<ii>> graph(805, vector<ii>(0));

void getInput() {

    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void Dijkstra(int st) {

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    dist[st][st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {

        ii cur = pq.top();
        pq.pop();

        if (dist[st][cur.Y] == cur.X) {
            for (int i=0; i<graph[cur.Y].size(); i++) {
                int next = graph[cur.Y][i].X;
                if (dist[st][next] > dist[st][cur.Y]+graph[cur.Y][i].Y) {
                    dist[st][next] = dist[st][cur.Y]+graph[cur.Y][i].Y;
                    pq.push({dist[st][next], next});
                }
            }
        }
    }
}

int main() {

    cin >> N >> E;
    getInput();

    cin >> v1 >> v2;
    Dijkstra(1);
    Dijkstra(v1);
    Dijkstra(v2);

    long long re = LLONG_MAX;
    if (dist[1][v1] != INF && dist[v1][v2] != INF && dist[v2][N] != INF)
        re = min(re, 1LL*dist[1][v1]+dist[v1][v2]+dist[v2][N]);
    if (dist[1][v2] != INF && dist[v2][v1] != INF && dist[v1][N] != INF)
        re = min(re, 1LL*dist[1][v2]+dist[v2][v1]+dist[v1][N]);

    if (re == LLONG_MAX) cout<<"-1";
    else cout<<re;
    return 0;
}