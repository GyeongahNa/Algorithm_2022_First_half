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
vector<int> result;
vector<int> indegree(32005, 0);
vector<vector<int>> graph(32005, vector<int>(0));

void setGraph() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        graph[A].push_back(B);
        indegree[B]++;
    }
}

void topologicalSort() {

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=1; i<=N; i++) {
        if (!indegree[i]) pq.push(i);
    }

    while (!pq.empty()) {

        int cur = pq.top();
        result.push_back(cur);
        pq.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (!indegree[next]) pq.push(next);
        }
    }
}

int main() {

    setGraph();
    topologicalSort();
    for (auto x : result) printf("%d ", x); 
    return 0;
}

/* 
queue 대신 priority_queue(최소힙)을 사용하여 가장 작은 노드를 먼저 result에 정렬
*/