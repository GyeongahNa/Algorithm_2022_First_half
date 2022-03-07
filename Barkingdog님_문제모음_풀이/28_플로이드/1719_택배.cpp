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
#define INF 1000000000

int n, m;
vector<vector<int>> dist(205, vector<int>(205, INF));
vector<vector<int>> nxt(205, vector<int>(205, 0));

void getInput() {

    for (int i=1; i<=n; i++) {
        dist[i][i] = 0;
        nxt[i][i] = i;
    }

    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;

        dist[a][b] = min(dist[a][b], t);
        dist[b][a] = min(dist[b][a], t);
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
}

void Floyd() {

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    nxt[i][j] = k;
                }
            }
        }
    }
}

int findFirst(int s, int e) {

    if (nxt[s][e] == e) return e;
    return findFirst(s, nxt[s][e]);
}

void printnxt() {

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!dist[i][j]) cout<<"- ";
            else cout<<findFirst(i, j)<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    getInput();
    Floyd(); 
    printnxt();
    return 0;
}

/*
nxt[s][e]: 정점 s에서 e까지 최단거리로 갈 때 마지막 중간지점
*/