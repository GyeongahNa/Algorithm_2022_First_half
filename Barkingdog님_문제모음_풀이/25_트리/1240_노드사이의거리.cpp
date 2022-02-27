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
vector<vector<ii>> graph(10005, vector<ii>(0));

int bfs(int st, int en) {

    queue<int> q;
    vector<int> dist(10005, -1);
    vector<int> parent(10005, 0);

    q.push(st);
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
        }
    }
    return dist[en];
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N-1; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        graph[x].push_back({y, d});
        graph[y].push_back({x, d});
    }

    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", bfs(x, y));
    }
    return 0;
}