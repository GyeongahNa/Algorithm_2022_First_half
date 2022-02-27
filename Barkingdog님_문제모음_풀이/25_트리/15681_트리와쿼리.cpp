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

int N, R, Q;
vector<vector<int>> graph(100005, vector<int>(0));
vector<int> parent(100005, 0);
vector<int> nSubtrees(100005, 0);

void dfs(int node) {

    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (next == parent[node]) continue;
        parent[next] = node;
        dfs(next);
    }
}

void cntSubtrees(int node) {

    nSubtrees[node] = 1;
    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        if (next == parent[node]) continue;
        cntSubtrees(next);
        nSubtrees[node] += nSubtrees[next];
    }
}

int main() {

    scanf("%d %d %d", &N, &R, &Q);
    for (int i=0; i<N-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(R);
    cntSubtrees(R);
    
    while (Q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", nSubtrees[x]);
    }
    return 0;
}