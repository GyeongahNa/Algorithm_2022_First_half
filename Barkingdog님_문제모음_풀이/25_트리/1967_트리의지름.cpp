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

int N, mx;
vector<vector<ii>> graph(10005, vector<ii>(0));
vector<int> dist(10005, -1), parent(10005, 0);

void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int p, c, w;
        scanf("%d %d %d", &p, &c, &w);
        graph[p].push_back({c, w});
        graph[c].push_back({p, w});
    }
}

void bfs(int st) {

    queue<int> q;
    q.push(st);
    
    for (int i=0; i<10005; i++) {
        parent[i] = 0;
        dist[i] = -1;
    }
    dist[st] = 0;
    
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].X;
            if (next == parent[cur]) continue;
            q.push(next);
            parent[next] = cur;
            dist[next] = dist[cur]+graph[cur][i].Y;
            mx = max(mx, dist[next]);
        }
    }
}

int main() {

    setGraph();
    for (int i=1; i<=N; i++) bfs(i);
    printf("%d\n", mx);
    return 0;
}