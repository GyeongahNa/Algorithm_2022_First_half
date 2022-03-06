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
using ss = pair<string, string>;

#define X first
#define Y second
#define INF 1000000000

int n, m, k;
vector<vector<int>> dist(255, vector<int>(255, INF));

void getInput() {

    cin >> n >> m;
    for (int i=1; i<=n; i++) dist[i][i] = 0;

    while (m--) {
        int u, v, b;
        cin >> u >> v >> b;
        if (!b) {
            dist[u][v] = 0;
            dist[v][u] = 1;
        }
        else {
            dist[u][v] = 0;
            dist[v][u] = 0;
        }
    }
}

void Floyd() {

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    getInput();
    Floyd();
    
    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout<<dist[s][e]<<"\n"; 
    }
    return 0;
}