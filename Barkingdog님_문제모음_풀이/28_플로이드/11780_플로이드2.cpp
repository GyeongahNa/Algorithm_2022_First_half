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

int N, M;
vector<vector<long long>> dist(105, vector<long long>(105, INT_MAX));
vector<vector<int>> nxt(105, vector<int>(105, 0));

void Floyd() {

    for (int i=1; i<=N; i++) {
        dist[i][i] = 0;
        nxt[i][i] = i;
    }

    for (int i=0; i<M; i++) {
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);
        if (c < dist[a][b]) {
            dist[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

void printDist() {

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (dist[i][j] == INT_MAX) printf("0 ");
            else printf("%lld ", dist[i][j]);
        }
        printf("\n");
    }
}

// 정점 i에서 j까지 최단거리로 이동하는 경로 복원
void getPath(int i, int j, vector<int>& v) {

    v.push_back(i);
    if (nxt[i][j] == j) {
        v.push_back(j);
        return ;
    }
    getPath(nxt[i][j], j, v);
}

void printPath() {

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i == j || dist[i][j] == INT_MAX) {
                printf("0\n");
                continue;
            }
            vector<int> v;
            getPath(i, j, v);
            printf("%d ", (int)v.size());
            for (auto x : v) printf("%d ", x);
            printf("\n");
        }
    }
}

int main() {

    scanf("%d\n%d", &N, &M);
    Floyd();
    printDist();
    printPath();
    return 0;
}