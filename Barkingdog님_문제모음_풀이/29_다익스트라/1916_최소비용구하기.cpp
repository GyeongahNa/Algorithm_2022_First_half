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
using lli = pair<long long, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define INF LLONG_MAX

int N, M, st, en;
vector<long long> dist(1005, INF);
vector<vector<ii>> graph(2005, vector<ii>(0));
priority_queue<lli, vector<lli>, greater<lli>> pq;

void getInput() {

    cin >> N >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> st >> en;
}

void Dijkstra(int st) {

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {

        lli cur = pq.top();
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

    getInput();
    Dijkstra(st);
    cout<<dist[en];
    return 0;
}