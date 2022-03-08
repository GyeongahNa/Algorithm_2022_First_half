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

int n, m, x;

vector<int> tback(1005, INF), tgo(1005, INF);
vector<vector<ii>> graph(1005, vector<ii>(0));

void getInput() {

    while (m--) {
        int s, e, t;
        cin >> s >> e >> t;
        graph[s].push_back({e, t});
    }
}

void Dijkstra(int st, vector<int>& dist) {

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    for (int i=0; i<1005; i++) dist[i] = INF;
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

    cin >> n >> m >> x;
    getInput();
    Dijkstra(x, tback);

    int mx = 0;
    for (int i=1; i<=n; i++) {
        Dijkstra(i, tgo);
        mx = max(mx, tgo[x]+tback[i]);
    }
    cout<<mx;
    return 0;
}