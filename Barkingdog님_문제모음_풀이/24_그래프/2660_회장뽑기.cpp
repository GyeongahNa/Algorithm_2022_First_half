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
vector<vector<int>> graph(60, vector<int>(0));
vector<int> score(60);

int bfs(int st) {

    queue<int> q;
    vector<bool> visited(60);
    q.push(st);
    visited[st] = true;

    int score = -1;
    while (!q.empty()) {

        int sz = q.size();
        while (sz--) {

            int cur = q.front();
            q.pop();

            for (int i=0; i<graph[cur].size(); i++) {
                int next= graph[cur][i];
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        score++;
    }
    return score;
}

int main() {

    scanf("%d", &N);
    while (1) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == -1 || v == -1) break;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int mn = INT_MAX;
    for (int i=1; i<=N; i++) {
        score[i] = bfs(i);
        mn = min(mn, score[i]);
    }

    vector<int> ans;
    for (int i=1; i<=N; i++) {
        if (score[i] != mn) continue;
        ans.push_back(i);
    }

    printf("%d %d\n", mn, (int)ans.size());
    for (auto x : ans) printf("%d ", x);
    return 0;
}