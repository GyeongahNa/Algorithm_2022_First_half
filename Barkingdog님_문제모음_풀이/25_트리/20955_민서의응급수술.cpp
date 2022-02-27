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

int N, M, nGraph, nCycle;
vector<int> parent(100005, 0);
vector<bool> visited(100005, false);
vector<vector<int>> graph(100005, vector<int>(0));

void bfs(int node) {

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) {
                if (next != parent[cur]) nCycle++;
                continue;
            }
            q.push(next);
            visited[next] = true;
            parent[next] = cur;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        nGraph++;
        bfs(i);
    }

    printf("%d", (nGraph-1)+nCycle/2);
    return 0;
}