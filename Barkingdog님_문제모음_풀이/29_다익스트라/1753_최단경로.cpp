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

int V, E, K;
vector<int> dist(20005, INF);
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<vector<ii>> graph(20005, vector<ii>(0));

void getInput() {

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
}

void Dijkstra(int st) {

    dist[st] = 0;
    pq.push({0, st}); //{거리, 정점}

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

    cin >> V >> E >> K;
    getInput();
    Dijkstra(K);

    for (int i=1; i<=V; i++) {
        if (dist[i] == INF) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}