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
using dd = pair<double, double>;
using dii = tuple<double, int, int>;

#define X first
#define Y second

int N, M;
double tot;
vector<dii> edge;
vector<dd> pos(1005);
vector<int> parent(1005, 0), nrank(1005, 1);


void setEdge() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        pos[i] = {x, y};
    }

    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            double dx = pos[i].X-pos[j].X;
            double dy = pos[i].Y-pos[j].Y;
            edge.push_back({sqrt(dx*dx+dy*dy), i, j});
        }
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

void mergeConnected() {

    for (int i=0; i<M; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        merge(n1, n2);
    }
}

void Kruscal() {

    for (auto x : edge) {
        double cost;
        int u, v;
        tie(cost, u, v) = x;
        if (find(u) == find(v)) continue;
        merge(u, v);
        tot += cost;
    }
}

int main() {

    setEdge();
    initialize();
    mergeConnected();
    Kruscal();
    printf("%.2f", tot);
    return 0;
}