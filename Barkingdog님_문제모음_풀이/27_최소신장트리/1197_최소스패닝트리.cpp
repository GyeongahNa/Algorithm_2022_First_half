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

int V, E, tot;
vector<int> parent(100005, 0);
vector<int> nrank(100005, 1);
vector<iii> edge;

void setEdge() {

    scanf("%d %d", &V, &E);
    for (int i=0; i<E; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        edge.push_back({C, A, B});
    }
    sort(edge.begin(), edge.end());
}

void initialize() {
    for (int i=1; i<=V; i++) parent[i] = i;
}

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {

    u = find(u);
    v = find(v);

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
        if (cnt == V-1) break;
    }
}

int main() {

    setEdge();
    initialize();
    Kruscal();
    printf("%d", tot);
    return 0;
}