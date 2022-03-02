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

int N;
vector<int> t(10005, 0);
vector<int> dist(10005, 0);
vector<int> indegree(10005, 0);
vector<vector<int>> graph(10005, vector<int>(0));

void setGraph() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &t[i]);
        int num;
        scanf("%d", &num);
        for (int j=0; j<num; j++) {
            int node;
            scanf("%d", &node);
            int mn = min(i, node);
            int mx = max(i, node);
            graph[mn].push_back(mx);
            indegree[mx]++;
        }
    }
}

void topologicalSort() {

    queue<int> q;

    for (int i=1; i<=N; i++) {
        if (!indegree[i]) {
            q.push(i);
            dist[i] = t[i];
        }
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

    setGraph();
    topologicalSort();

    int mx = 0;
    for (int i=1; i<=N; i++) 
        mx = max(dist[i], mx);
    printf("%d", mx);
    return 0;
}