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

int N, M;
vector<vector<long long>> dist(105, vector<long long>(105, INT_MAX));

void Floyd() {
    
    // 아무 노드도 거치지 않았을 때 두 정점 사이의 최솟값
    for (int i=1; i<=N; i++) dist[i][i] = 0;
    for (int i=0; i<M; i++) {
        long long a, b, c; 
        scanf("%lld %lld %lld", &a, &b, &c);
        dist[a][b] = min(dist[a][b], c); 
    }

    // 중간 노드를 거쳤을 때 두 정점 사이의 최솟값
    for (int i=1; i<=N; i++) {
        for (int s=1; s<=N; s++) {
            for (int t=1; t<=N; t++)
                dist[s][t] = min(dist[s][t], dist[s][i]+dist[i][t]);
        }
    }
}

void printdist() {

    for (int s=1; s<=N; s++) {
        for (int t=1; t<=N; t++) {
            if (dist[s][t] == INT_MAX) printf("0 ");
            else printf("%lld ", dist[s][t]);
        }
        printf("\n");
    }
}

int main() {

    scanf("%d %d", &N, &M);
    Floyd();
    printdist();  
}