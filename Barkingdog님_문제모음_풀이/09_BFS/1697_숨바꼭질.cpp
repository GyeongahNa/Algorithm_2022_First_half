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

#define X first
#define Y second

int N, K;
int dist[200001];

int main() {
    
    scanf("%d %d", &N, &K);
    memset(dist, -1, sizeof(dist));

    if (N == K) {
        printf("0");
        return 0;
    }

    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        int newx[3] = {cur-1, cur+1, cur*2};
        for (int nx : newx) {
            if (nx < 0 || nx >= 200000) continue;
            if (dist[nx] != -1) continue;

            q.push(nx);
            dist[nx] = dist[cur]+1;
            if (nx == K) {
                printf("%d", dist[nx]);
                return 0;
            }
        }
    }
    return 0;
}

/*1차원에서의 BFS*/