#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

//dp[i][j][k]: graph[1][k]로 출발하여 dp[i][j]에 도착했을 때 최소비용

int N;
int graph[100005][3];
long long dp[100005][3][3];

void setGraph() {

    for (int i=1; i<=N; i++) {
        for (int j=0; j<3; j++)
            scanf("%d", &graph[i][j]);
    }
}

void dynamic() {

    dp[1][0][0] = graph[1][0];
    dp[1][1][0] = graph[1][0]+graph[1][1];
    dp[1][2][0] = graph[1][0]+graph[1][1]+graph[1][2];

    dp[1][1][1] = graph[1][1];
    dp[1][2][1] = graph[1][1]+graph[1][2];
    dp[1][2][2] = graph[1][2]; 
    
    dp[1][0][1] = 10000000;
    dp[1][0][2] = 10000000;
    dp[1][1][2] = 10000000;

    for (int i=2; i<=N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][0][j] = min(dp[i-1][0][j], dp[i-1][1][j])+graph[i][0];
            dp[i][1][j] = min({dp[i-1][0][j], dp[i-1][1][j], dp[i-1][2][j], dp[i][0][j]})+graph[i][1];
            dp[i][2][j] = min({dp[i-1][1][j], dp[i-1][2][j], dp[i][1][j]})+graph[i][2];
        }
    }
}

int main() {

    int idx = 1;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        setGraph();
        dynamic();
        printf("%d. %lld\n", idx, dp[N][1][1]);
        idx++;
    }
    return 0;
}