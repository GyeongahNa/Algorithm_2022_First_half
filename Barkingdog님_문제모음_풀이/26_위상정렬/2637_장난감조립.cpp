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
vector<int> basic;
vector<int> indegree(105, 0);
vector<vector<ii>> graph(105, vector<ii>(0));
vector<vector<int>> npiece(105, vector<int>(105, 0));

void setGraph() {

    scanf("%d\n%d", &N, &M);
    for (int i=0; i<M; i++) {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        graph[y].push_back({x, k});
        indegree[x]++;
    }
}

void topologicalSort() {

    queue<int> q;

    for (int i=1; i<=N; i++) {
        if (!indegree[i]) {
            q.push(i);
            basic.push_back(i);
            npiece[i][i]++;
        }
    }

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i].X;
            indegree[next]--;
            if (!indegree[next]) q.push(next);
            for (int j=1; j<105; j++)
                npiece[next][j] += npiece[cur][j]*graph[cur][i].Y;            
        }
    }
}

int main() {

    setGraph();
    topologicalSort();
    for (auto x : basic) printf("%d %d\n", x, npiece[N][x]);
    return 0;
}