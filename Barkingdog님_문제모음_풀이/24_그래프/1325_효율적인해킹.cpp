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
vector<vector<int>> graph(10005, vector<int>(0));
vector<int> score(10005);

int bfs(int st) {

    queue<int> q;
    vector<bool> visited(10005, false);
    q.push(st); 
    visited[st] = true;

    int cnt = 0;
    while (!q.empty()) {

        int cur = q.front();
        q.pop();
        cnt++;

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }
    return cnt;
}

int main() {

    scanf("%d %d", &N, &M);
    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[y].push_back(x);
    }

    int mx = -1;
    for (int i=1; i<=N; i++) {
        score[i] = bfs(i);
        mx = max(mx, score[i]);
    }

    for (int i=1; i<=N; i++) {
        if (score[i] != mx) continue;
        printf("%d ", i);
    }
    return 0;
}