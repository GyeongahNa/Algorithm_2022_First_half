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

int N, M, K;
vector<long long> dist(100005, INF);
priority_queue<lli, vector<lli>, greater<lli>> pq;
vector<vector<ii>> graph(100005, vector<ii>(0));

void setInput() {

    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[v].push_back({u, c});
    }

    while (K--) {
        int x;
        cin >> x;
        pq.push({0, x});
        dist[x] = 0;
    }
}

void Dijkstra() {

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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> K;
    setInput();
    Dijkstra();

    long long mx = -1;
    int mxidx = -1;
    for (int i=1; i<=N; i++) {
        if (dist[i] <= mx) continue;
        mx = dist[i];
        mxidx = i;
    }

    cout<<mxidx<<"\n";
    cout<<mx;
    return 0;
}

/*
그래프의 간선을 반대로 입력 받은 후, 
면접장에서 각 도시까지의 최단 거리를 구함 
*/