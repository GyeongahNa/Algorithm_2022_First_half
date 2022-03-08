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

int V, E;
vector<vector<ii>> graph(105, vector<ii>(0));
vector<int> dist(105, INF);
vector<bool> fix(105, false);

void getInput() {

    cin >> V >> E;
    while (E--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }  
}

// O(V^2+E)
void Dijkstra_naive(int st) {

    dist[st] = 0;

    while (true) {

        // 최단거리가 확정되지 않은 정점들 중 가장 거리가 짧은 정점 선택
        int idx = -1;
        for (int i=1; i<=V; i++) {
            if (fix[i]) continue;
            if (idx == -1) idx = i;
            else if (dist[i] < dist[idx]) idx = i;
        }

        // 확정할 정점이 없을 시 종료
        if (idx == -1 || dist[idx] == INF) break;

        // 확정한 정점에서 갈 수 있는 정점들에 대해 최단 거리 갱신
        fix[idx] = true;
        for (int i=0; i<graph[idx].size(); i++) {
            int next = graph[idx][i].X;
            if (fix[next]) continue;
            dist[next] = min(dist[next], dist[idx]+graph[idx][i].Y);
        }
    }
}

int main() {

    getInput();
    Dijkstra_naive(1);

    for (int i=1; i<=V; i++) cout<<dist[i]<<" ";
    return 0;
}

/*
input:
6 8
1 2 3
1 3 2
1 4 5
2 3 2
2 5 8
3 4 2
4 5 6
5 6 1

output:
0 3 2 4 10 11
*/