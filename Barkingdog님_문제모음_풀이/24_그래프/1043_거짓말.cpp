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

int N, M, T, cnt;
vector<int> tP;
vector<vector<int>> party(55, vector<int>(0));
vector<vector<int>> graph(55, vector<int>(55));
vector<bool> visited(55);

void getInput() {

    scanf("%d %d\n%d", &N, &M, &T);

    for (int i=0; i<T; i++) {
        int x;
        scanf("%d", &x);
        tP.push_back(x);
    }

    for (int i=0; i<M; i++) {
        int n;
        scanf("%d", &n);
        for (int j=0; j<n; j++) {
            int x;
            scanf("%d", &x);
            party[i].push_back(x);
        }
    }

    for (int i=0; i<M; i++) {
        for (auto p1 : party[i]) {
            for (auto p2 : party[i]) {
                graph[p1][p2] = 1;
                graph[p2][p1] = 1;
            }
        }
    }
}

void bfs(int st) {

    queue<int> q;
    q.push(st);
    visited[st] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            if (!graph[cur][i]) continue;
            if (visited[i]) continue;
            q.push(i);
            visited[i] = true;
        }
    }
}

void cntParty() {

    for (int i=0; i<M; i++) {
        bool check = true;
        for (auto x : party[i]) {
            if (!visited[x]) continue;
            check = false;
            break;
        }
        if (check) cnt++;
    }
}

int main() {

    getInput();

    for (auto x : tP) {
        if (visited[x]) continue;
        bfs(x);
    }

    cntParty();
    printf("%d", cnt);
    return 0;
}