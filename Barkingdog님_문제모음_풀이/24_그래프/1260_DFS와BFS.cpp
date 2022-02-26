#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

int N, M, V;
vector<vector<int>> graph(1005, vector<int>(1005));
vector<bool> bfsvisited(1005), dfsvisited(1005);

void dfs(int node) {

    printf("%d ", node);
    dfsvisited[node] = true;

    for (int i=0; i<graph[node].size(); i++) {
        if (!graph[node][i] || dfsvisited[i]) continue;
        dfs(i);
    }
}

void bfs(int st) {

    queue<int> q;
    q.push(st);
    bfsvisited[st] = true;

    while (!q.empty()) {

        int cur = q.front();
        printf("%d ", cur);
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            if (!graph[cur][i] || bfsvisited[i]) continue;
            q.push(i);
            bfsvisited[i] = true;
        }
    }
}


int main() {

    scanf("%d %d %d", &N, &M, &V);
    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    dfs(V); printf("\n");
    bfs(V);
    return 0;
}

/*인접리스트 대신 인접행렬 사용*/