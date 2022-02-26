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
vector<vector<int>> graph(105, vector<int>(0));
vector<int> score(105);

int bfs(int st) {

    queue<int> q;
    vector<bool> visited(105, false);
    q.push(st);
    visited[st] = true;

    int score = 0, dist = 0;
    while (!q.empty()) {

        int sz = q.size();
        score += dist*sz;
        while (sz--) {

            int cur = q.front();
            q.pop();
            
            for (int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur][i];
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        dist++;
    }
    return score;
}

int main() {

    scanf("%d %d", &N, &M);
    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int mn = INT_MAX;
    for (int i=1; i<=N; i++) {
        score[i] = bfs(i);
        mn = min(mn, score[i]);
    }

    for (int i=1; i<=N; i++) {
        if (score[i] != mn) continue;
        printf("%d", i);
        break;
    }
    return 0;
}
