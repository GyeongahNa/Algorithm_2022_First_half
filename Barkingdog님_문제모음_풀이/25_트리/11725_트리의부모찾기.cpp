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

int N;
vector<vector<int>> graph(100005, vector<int>(0));
vector<int> parent(100005);

void bfs() {

    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (next == parent[cur]) continue;
            q.push(next);
            parent[next] = cur;
        }
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();
    for (int i=2; i<=N; i++) printf("%d\n", parent[i]);
    return 0;
}