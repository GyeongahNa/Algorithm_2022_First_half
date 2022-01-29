#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int pop[15];
int graph[15][15];

int mn = INT_MAX;


void bfs(int start, bool visited[15], vector<int> &v) {

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i=1; i<=N; i++) {
            if (v[cur] != v[i]) continue;
            if (!graph[cur][i] || visited[i]) continue;

            q.push(i);
            visited[i] = true;
        }
    }

}


bool check(vector<int>& v) {

    int t1, t2;
    for (int i=1; i<=N; i++) {
        if (!v[i]) t1 = i;
        else t2 = i;
    }

    bool visited[15];
    memset(visited, false, sizeof(visited));
    bfs(t1, visited, v);
    bfs(t2, visited, v);

    for (int i=1; i<=N; i++) {
        if (!visited[i]) return false;
    }
    return true;
}


int getDiff(vector<int>& v) {

    int p[2] = {0, 0};
    for (int i=0; i<v.size(); i++) {
        if (v[i] == 0) p[0] += pop[i];
        else p[1] += pop[i];
    }
    return abs(p[0]-p[1]);
}


void divideArea() {

    for (int t=1; t<(1<<N)-1; t++) {

        int tmp = t;
        vector<int> v = {0};
        for (int i=0; i<N; i++) {
            v.push_back(tmp%2);
            tmp /= 2;
        }

        if (!check(v)) continue;
        mn = min(mn, getDiff(v));
    }
}


int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &pop[i]);
    
    for (int i=1; i<=N; i++) {
        int M;
        scanf("%d", &M);
        for (int j=0; j<M; j++) {
            int x;
            scanf("%d", &x);
            graph[i][x] = 1;
        }
    }

    divideArea();
    if (mn == INT_MAX) mn = -1;
    printf("%d", mn);
    return 0;
}