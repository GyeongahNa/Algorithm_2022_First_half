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

int N, a, b, w;
vector<vector<ii>> graph(100005, vector<ii>(0));
vector<int> dist(100005, -1);

void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &a);
        while (1) {
            scanf("%d", &b);
            if (b == -1) break;
            scanf("%d", &w);
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }       
    }
}

ii bfs(int st) {

    queue<int> q;
    q.push(st);

    for (int i=0; i<100005; i++) dist[i] = -1;
    dist[st] = 0;

    int mxidx = st, mx = 0;
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].X;
            if (dist[next] != -1) continue;
            
            q.push(next);
            dist[next] = dist[cur]+graph[cur][i].Y;

            if (mx < dist[next]) {
                mx = dist[next];
                mxidx = next;
            }
        }
    }
    return {mxidx, mx};
}

int main() {

    setGraph();
    printf("%d", bfs(bfs(1).X).Y);
    return 0;
}

/*
트리지름(두 노드 사이의 가장 먼 거리) 구하는 법:
모든 노드를 루트로 하여 각 노드까지의 거리를 구하고 최댓값 구하는 방법 - 시간복잡도 O(N^2)
임의의 노드로 부터 가장 먼 지점 탐색, 그 지점으로 부터 가장 먼 지점까지의 거리를 구하는 방법 - 시간 복잡도 O(N)
*/