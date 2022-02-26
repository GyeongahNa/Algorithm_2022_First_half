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

int K, N, M;
vector<vector<int>> graph(20005, vector<int>(0));
vector<int> color(20005, 0);

void clear() {

    for (int i=1; i<20005; i++) {
        graph[i].clear();
        color[i] = 0;
    }
}

void getEdge() {

    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void bfs(int st) {

    queue<int> q;
    q.push(st);
    color[st] = 1;

    while (!q.empty()) {
        
        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (color[next]) continue;
            q.push(next);
            color[next] = 3-color[cur];
        }
    }
}

bool check() {

    for (int i=1; i<=N; i++) {
        for (int j=0; j<graph[i].size(); j++) {
            int node = graph[i][j];
            if (color[i] == color[node]) return false;
        }
    }
    return true;
}

int main() {

    scanf("%d", &K);
    while (K--) {

        scanf("%d %d", &N, &M);
        clear();
        getEdge();

        for (int i=1; i<=N; i++) {
            if (color[i]) continue;
            bfs(i);
        }

        if (check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}