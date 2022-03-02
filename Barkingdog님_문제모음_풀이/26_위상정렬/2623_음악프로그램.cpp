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
vector<int> result;
vector<int> indegree(1005, 0);
vector<vector<bool>> graph(1005, vector<bool>(1005, false));

void setGraph() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int num;
        scanf("%d", &num);
        vector<int> v(num, 0);
        for (int i=0; i<num; i++) scanf("%d", &v[i]);
        for (int i=1; i<num; i++) {
            if (graph[v[i-1]][v[i]]) continue;
            graph[v[i-1]][v[i]] = true;
            indegree[v[i]]++;
        }
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
        result.push_back(cur);

        for (int i=1; i<=N; i++) {
            if (!graph[cur][i]) continue;
            indegree[i]--;
            if (!indegree[i]) q.push(i);
        }
    }
}

int main() {

    setGraph();
    topologicalSort();

    if (result.size() != N) printf("0\n");
    else {
        for (auto x : result) printf("%d\n", x);
    }
    return 0;
}

/*같은 노드가 여러번 입력될 수 있으므로 인접리스트가 아닌 인접행렬로 처리*/