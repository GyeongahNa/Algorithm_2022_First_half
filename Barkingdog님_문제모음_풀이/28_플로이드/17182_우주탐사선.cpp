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

int N, K;
int mn = INT_MAX;
vector<int> arr(105, 0);
vector<bool> visited(105, false);
vector<vector<int>> dist(105, vector<int>(105, 0));

void Floyd() {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) scanf("%d", &dist[i][j]);
    }

    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

void backTracking(int idx) {

    if (idx == N) { 
        int d = 0;
        for (int i=1; i<N; i++) 
            d += dist[arr[i-1]][arr[i]];
        mn = min(mn, d);
        return ;
    }

    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        arr[idx] = i;
        visited[i] = true;
        backTracking(idx+1);
        visited[i] = false;
    }
}

int main() {

    scanf("%d %d", &N, &K);
    Floyd();

    arr[0] = K;
    visited[K] = true;
    backTracking(1);
    printf("%d", mn);
    return 0;
}