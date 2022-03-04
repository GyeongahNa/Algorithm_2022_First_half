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

int N, M, tot, mx;
vector<iii> edge;
vector<int> parent(100005, 0);
vector<int> nrank(100005, 1);


void setEdge() {

    scanf("%d %d", &N, &M);
    while (M--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        edge.push_back({C, A, B});
    }
    sort(edge.begin(), edge.end());
}

void initialize() {

    for (int i=1; i<=N; i++) parent[i] = i;
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

    for (auto x : edge) {
        int cost, u, v;
        tie(cost, u, v) = x;
        if (find(u) == find(v)) continue;
        merge(u, v);
        mx = max(mx, cost);
        tot += cost;
    }
}

int main() {

    setEdge();
    initialize();
    Kruscal();
    printf("%d", tot-mx);
    return 0;
}