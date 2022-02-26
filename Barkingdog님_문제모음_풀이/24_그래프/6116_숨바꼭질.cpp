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
int mx = -1;
vector<vector<int>> graph(50005, vector<int>(0));
vector<int> dist(50005, -1);

void bfs() {

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();
        mx = max(mx, dist[cur]);

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (dist[next] != -1) continue;
            q.push(next);
            dist[next] = dist[cur]+1;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs();
    vector<int> ans;
    for (int i=1; i<=N; i++) {
        if (dist[i] != mx) continue;
        ans.push_back(i);
    }
    printf("%d %d %d", ans[0], mx, (int)ans.size());
    return 0;
}