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

int N, K;
int dist[200000];

int main() {

    scanf("%d %d", &N, &K);
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push({N});
    dist[N] = 0;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        int x[3] = {2*cur, cur-1, cur+1};
        for (int n : x) {
            if (n < 0 || n >= 200000) continue;
            if (dist[n] != -1) continue;
            if (n == 2*cur) dist[n] = dist[cur];
            else dist[n] = dist[cur]+1;
            q.push(n);
        }
    }
    printf("%d", dist[K]);
    return 0;
}