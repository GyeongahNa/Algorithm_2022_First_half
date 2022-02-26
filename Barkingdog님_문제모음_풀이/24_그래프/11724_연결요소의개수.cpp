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

int N, M, cnt;
vector<vector<int>> graph(1005, vector<int>(0));
vector<bool> visited(1005);

void bfs(int st) {

    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        cnt++;
        bfs(i); 
    }
    printf("%d\n", cnt);
    return 0;
}