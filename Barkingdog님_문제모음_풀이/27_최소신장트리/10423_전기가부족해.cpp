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

int N, M, K, tot;
vector<iii> edge;
vector<int> parent(1005, 0), nrank(1005, 1);

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

void setEdge() {

    for (int i=0; i<K; i++) {
        int x;
        scanf("%d", &x);
        merge(0, x);
    }

    for (int i=0; i<M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());
}

void kruscal() {

    for (auto x : edge) {
        int cost, u, v;
        tie(cost, u, v) = x;
        if (find(u) == find(v)) continue;
        tot += cost;
        merge(u, v);
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    initialize();
    setEdge();
    kruscal();
    printf("%d", tot);
    return 0;
}