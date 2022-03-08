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

int N, M, st, en;
vector<int> pre(1005, 0);
vector<int> dist(1005, INF);
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<vector<ii>> graph(1005, vector<ii>(0));

void getInput() {

    while (M--) {
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
                int next= graph[cur.Y][i].X;
                if (dist[next] > dist[cur.Y]+graph[cur.Y][i].Y) {
                    dist[next] = dist[cur.Y]+graph[cur.Y][i].Y;
                    pq.push({dist[next], next});
                    pre[next] = cur.Y;
                }
            }
        }
    }
}

void getPath(int st, int en, vector<int>& v) {

    if (st == en) {
        v.push_back(st);
        return ;
    }
    getPath(st, pre[en], v);
    v.push_back(en);
}

int main() {

    cin >> N >> M;
    getInput();

    cin >> st >> en;
    Dijkstra(st);

    vector<int> v;
    getPath(st, en, v);

    cout<<dist[en]<<"\n";
    cout<<(int)v.size()<<"\n";
    for (auto x : v) cout<<x<<" ";
    return 0;
}