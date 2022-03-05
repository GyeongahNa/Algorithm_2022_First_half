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

int n, m, r, mx;
vector<int> t(105, 0);
vector<vector<long long>> dist(105, vector<long long>(105, INT_MAX));

void getInput() {

    scanf("%d %d %d", &n, &m, &r);
    for (int i=1; i<=n; i++) {
        scanf("%d", &t[i]);
        dist[i][i] = 0;
    }

    while (r--) {
        int a, b;
        long long l;
        scanf("%d %d %lld", &a, &b, &l);
        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
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

void getMax() {

    for (int i=1; i<=n; i++) {
        int cnt = 0;
        for (int j=1; j<=n; j++) {
            if (dist[i][j] <= m) cnt += t[j];
        }
        mx = max(mx, cnt);
    }
}

int main() {

    getInput();
    Floyd();
    getMax();
    printf("%d", mx);
    return 0;
}