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

int N, M;
vector<vector<int>> graph(505, vector<int>(0));
vector<bool> visited(505);
vector<int> parent(505);

void clear() {

    for (int i=0; i<505; i++) {
        graph[i].clear();
        visited[i] = false;
        parent[i] = 0;
    }
}

void getEdge() {

    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

bool bfs(int node) {

    queue<int> q;
    q.push(node);
    visited[node] = true;

    bool istree = true;
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) {
                if (next != parent[cur]) istree = false;
                continue;
            }
            q.push(next);
            visited[next] = true;
            parent[next] = cur;
        }
    }
    return istree;
}

int main() {

    int ncase = 1;
    while (1) {
        scanf("%d %d", &N, &M);
        if (!N && !M) break;
        clear();
        getEdge();

        int cnt = 0;
        for (int i=1; i<=N; i++) {
            if (visited[i]) continue;
            if (bfs(i)) cnt++;
        }
        
        if (!cnt) printf("Case %d: No trees.\n", ncase);
        else if (cnt == 1) printf("Case %d: There is one tree.\n", ncase);
        else printf("Case %d: A forest of %d trees.\n", ncase, cnt);
        ncase++;
    }
    return 0;
}