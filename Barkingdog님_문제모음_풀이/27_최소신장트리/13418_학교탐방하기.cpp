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

int N, M, wcnt, bcnt;
vector<iii> wEdge, bEdge;
vector<int> parent(1005, 0), nrank(10005, 1);

void setEdge() {

    scanf("%d %d", &N, &M);
    M++;
    while (M--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        if (!C) { //오르막길
            bEdge.push_back({1, A, B});
            wEdge.push_back({-1, A, B});
        }
        else { //내리막길
            bEdge.push_back({0, A, B});
            wEdge.push_back({0, A, B});
        }
    }
    sort(wEdge.begin(), wEdge.end());
    sort(bEdge.begin(), bEdge.end());
}

void initialize() {

    for (int i=0; i<=N; i++) {
        parent[i] = i;
        nrank[i] = 1;
    }
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

void Kruscal(vector<iii>& Edge, int& cnt) {

    initialize();

    for (auto x : Edge) {
        int cost, u, v;
        tie(cost, u, v) = x;
        if (find(u) == find(v)) continue;
        merge(u, v);
        if (cost) cnt++;
    }
}

int main() {

    setEdge();
    Kruscal(wEdge, wcnt);
    Kruscal(bEdge, bcnt);
    printf("%d", wcnt*wcnt-bcnt*bcnt);
    return 0;
}