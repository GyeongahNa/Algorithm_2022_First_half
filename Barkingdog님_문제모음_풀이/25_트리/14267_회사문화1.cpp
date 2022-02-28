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
vector<vector<int>> graph(100005, vector<int>(0));
vector<int> dp(100005, 0);

void setGraph() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        int p;
        scanf("%d", &p);
        if (p == -1) continue;
        graph[p].push_back(i);
    }

    for (int i=0; i<M; i++) {
        int n, w;
        scanf("%d %d", &n, &w);
        dp[n] += w;
    }
}

void dfs(int node) {

    for (int i=0; i<graph[node].size(); i++) {
        int next = graph[node][i];
        dp[next] += dp[node];
        dfs(next);
    }
}

int main() {

    setGraph();
    dfs(1);

    for (int i=1; i<=N; i++) printf("%d ", dp[i]);
    return 0;
}