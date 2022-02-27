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

int N, root, subnode, tot, nremoved;
vector<vector<int>> graph(55, vector<int>(0));
vector<int> parent(55, -1);

void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int p;
        scanf("%d", &p);
        if (p == -1) {
            root = i;
            continue;
        }
        graph[p].push_back(i);
        graph[i].push_back(p);
    }
}

void dfs(int node, int& num) {

    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (next == parent[node]) continue;
        parent[next] = node;
        dfs(next, num);
    }

    int sz = graph[node].size();
    if (parent[node] != -1) sz--;
    if (!sz) num++;
}

int main() {

    setGraph();
    dfs(root, tot);
    
    scanf("%d", &subnode);
    dfs(subnode, nremoved);

    int re = tot-nremoved;
    if (parent[subnode] != -1) {
        int sz = graph[parent[subnode]].size();
        if (parent[parent[subnode]] != -1) sz--;
        sz--;
        if (!sz) re++;
    }
    printf("%d", re);
    return 0;
}

/*
반례 찾아 고친 문제
- dfs에서 해당 노드가 리프인지 확인하는 방법: 연결된 노드의 개수 1개(X), 부모 노드를 제외한 연결 노드의 개수 0개(O)
- 서브트리를 제거할 때, 부모노드가 리프가 되는 경우가 있음
*/