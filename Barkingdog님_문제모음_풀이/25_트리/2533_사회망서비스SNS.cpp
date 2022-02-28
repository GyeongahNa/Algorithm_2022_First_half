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
vector<vector<int>> graph(1000005, vector<int>(0));
vector<int> parent(1000005, 0);
stack<int> nodes;

int dp[1000005][2];


void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(int st) {

    queue<int> q;
    q.push(st);
    nodes.push(st);
    
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (next == parent[cur]) continue;
            q.push(next);
            nodes.push(next);
            parent[next] = cur;
        }
    }
}

bool isleaf(int node) {

    int sz = graph[node].size();
    if (parent[node]) sz--;
    return !sz;
}

int main() {

    setGraph();
    bfs(1);
    
    while (!nodes.empty()) {

        int cur = nodes.top();
        nodes.pop();

        if (isleaf(cur)) {
            dp[cur][1] = 1;
            continue;
        }
        
        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
        dp[cur][1]++;
    }

    printf("%d", min(dp[1][0], dp[1][1]));
    return 0;
}

/*
dp[i][1]: i번 노드를 얼리어답터라 했을 때 (서브트리에 아이디어를 전파하기 위한) 최소 얼리어답터 수
dp[i][0]: i번 노드가 얼리어답터가 아닐 때 (서브트리에 아이디어를 전파하기 위한) 최소 얼리어답터 수
*/