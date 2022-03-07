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
#define INF 10000000

int N, M, T;
vector<vector<int>> height(305, vector<int>(305, INF));

void getInput() {

    for (int i=1; i<=N; i++) height[i][i] = 0;
    while (M--) {
        int u, v, h;
        cin >> u >> v >> h;
        height[u][v] = h;
    }
}

void Floyd() {

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++)
                height[i][j] = min(height[i][j], max(height[i][k], height[k][j]));
        }
    }
}

int main() {

    cin >> N >> M >> T;
    getInput();
    Floyd();
    
    while (T--) {
        int s, e;
        cin >> s >> e;
        if (height[s][e] == INF) cout<<"-1\n";
        else cout<<height[s][e]<<"\n";
    }
    return 0;
}