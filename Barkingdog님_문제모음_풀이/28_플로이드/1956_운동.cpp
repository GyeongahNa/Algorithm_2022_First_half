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
#define INF INT_MAX


int V, E;
long long re = INF;
vector<vector<long long>> dist(405, vector<long long>(405, INF));

void getInput() {

    for (int i=1; i<=V; i++) dist[i][i] = 0;
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
}

void Floyd() {

    for (int k=1; k<=V; k++) {
        for (int i=1; i<=V; i++) {
            for (int j=1; j<=V; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

void getShortest() {

    for (int i=1; i<=V; i++) { //출발, 도착 지점
        long long mn = INF;
        for (int j=1; j<=V; j++) { //중간 지점
            if (i == j) continue;
            if (dist[i][j] == INF || dist[j][i] == INF) continue;
            mn = min(mn, dist[i][j]+dist[j][i]);
        }
        re = min(re, mn);
    }
} 

int main() {

    cin >> V >> E;
    getInput();
    Floyd();
    getShortest();
    if (re == INF) cout<<-1;
    else cout << re;
    return 0;
}