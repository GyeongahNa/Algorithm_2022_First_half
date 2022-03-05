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

int N, M, K;
vector<ii> res;
vector<int> city;
vector<vector<long long>> dist(205, vector<long long>(205, INT_MAX));

void setInput() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) dist[i][i] = 0;
    
    while (M--) {
        int A, B;
        long long T;
        scanf("%d %d %lld", &A, &B, &T);
        dist[A][B] = min(dist[A][B], T);
    }

    scanf("%d", &K);
    while (K--) {
        int C;
        scanf("%d", &C);
        city.push_back(C);
    }
}

void Floyd() {

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}

void selectCity() {

    long long mn = LLONG_MAX;
    for (int k=1; k<=N; k++) {

        long long mx = 0;
        bool check = true;
        for (auto c : city) {
            if (dist[c][k] == INT_MAX || dist[k][c] == INT_MAX) {
                check = false;
                break;
            }
            mx = max(dist[c][k]+dist[k][c], mx);
        }
        if (!check) continue;
        res.push_back({k, mx});
        mn = min(mn, mx);
    }

    for (auto x : res) {
        if (x.Y == mn) printf("%d ", x.X);
    }
}

int main() {

    setInput();
    Floyd();
    selectCity();
    return 0;
}