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
int dist[200001];
int pre[200001];

int main() {

    scanf("%d %d", &N, &K);
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    pre[N] = -1;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        int dx[3] = {cur-1, cur+1, cur*2};
        for (int x : dx) {
            if (x < 0 || x >= 200001) continue;
            if (dist[x] != -1) continue;
            q.push(x);
            dist[x] = dist[cur]+1;
            pre[x] = cur;
        }
    }

    printf("%d\n", dist[K]);

    stack<int> st;
    int idx = K;
    while (idx != -1) {
        st.push(idx);
        idx = pre[idx];
    }

    while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}