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

int N, tot;
vector<iii> edge;
vector<int> nrank(305, 1);
vector<int> parent(305, 0);

void getInfo() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        int w;
        scanf("%d", &w);
        edge.push_back({w, 0, i});
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int c;
            scanf("%d", &c);
            edge.push_back({c, i, j});
        }
    }
    sort(edge.begin(), edge.end());
}

void initialize() {

    for (int i=0; i<=N; i++) parent[i] = i;
}

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);
    if (u == v) return ;
    if (nrank[u] > nrank[v]) swap(u, v);
    if (nrank[u] == nrank[v]) nrank[v]++;
    parent[u] = v;
}

void Kruscal() {

    int cnt = 0;
    for (auto x : edge) {
        int cost, u, v;
        tie(cost, u, v) = x;
        if (find(u) == find(v)) continue;
        merge(u, v);
        cnt++;
        tot += cost;
        if (cnt == N) break;
    }
}

int main() {

    getInfo();
    initialize();
    Kruscal();
    printf("%d", tot);
    return 0;
}