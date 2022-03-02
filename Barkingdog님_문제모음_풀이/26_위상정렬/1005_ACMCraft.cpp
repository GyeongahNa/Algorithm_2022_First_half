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

int T, N, K;
vector<int> t(1005, 0);
vector<int> dist(1005, 0);
vector<int> indegree(1005, 0);
vector<vector<int>> graph(1005, vector<int>(0));

void setGraph() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<1005; i++) {
        t[i] = 0;
        dist[i] = 0;
        indegree[i] = 0;
        graph[i].clear();
    }
    for (int i=1; i<=N; i++) scanf("%d", &t[i]);
    for (int i=0; i<K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        indegree[y]++;
    }
}

void topologicalSort() {

    queue<int> q;
    
    for (int i=1; i<=N; i++) {
        if (!indegree[i]) q.push(i);
        dist[i] = t[i];
    }

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (!indegree[next]) q.push(next);
            dist[next] = max(dist[next], dist[cur]+t[next]);
        }
    }
}

int main() {

    scanf("%d", &T);
    while (T--) {
        setGraph();
        topologicalSort();
        int w;
        scanf("%d", &w);
        printf("%d\n", dist[w]);
    }
}