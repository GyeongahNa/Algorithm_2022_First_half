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

int F, S, G, U, D;
int dist[10000001];

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(S);
    dist[S] = 0;

    int dx[2] = {U, -D};

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int d : dx) {
            int nx = cur+d;
            if (nx < 1 || nx > F) continue;
            if (dist[nx] != -1) continue;

            q.push(nx);
            dist[nx] = dist[cur]+1;
        }      
    }

    if (dist[G] == -1) printf("use the stairs");
    else printf("%d", dist[G]);
    return 0;  
}
