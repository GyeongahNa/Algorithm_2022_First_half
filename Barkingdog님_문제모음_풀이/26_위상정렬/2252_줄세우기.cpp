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
vector<int> v;
vector<int> indegree(32005, 0);
vector<vector<int>> graph(32005, vector<int>(0));

void setGraph() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        indegree[v]++;
    }
}

void topologicalSort() {

    queue<int> q;

    for (int i=1; i<=N; i++) {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty()) {

        int cur = q.front();
        q.pop();
        v.push_back(cur);

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (!indegree[next]) q.push(next);
        }
    }
}

int main() {

    setGraph();
    topologicalSort();

    for (auto x : v) printf("%d ", x);
    return 0;
}