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
using str = string;

#define X first
#define Y second

int N, M;
vector<str> father;
map<str, int> indegree;
map<str, set<str>> graph, result;

void setGraph() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char s[10];
        scanf("%s", s);
        indegree[s] = 0;
        graph.insert({s, {}});
        result.insert({s, {}});
    }

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        char s1[10], s2[10];
        scanf("%s %s", s1, s2);
        graph[s2].insert(s1);
        indegree[s1]++;
    }
}

void getFather() {

    for (auto it=indegree.begin(); it!=indegree.end(); it++) {
        if (!(it->Y)) father.push_back(it->X);
    }
}

void topologicalSort(str f) {

    queue<str> q;
    q.push(f);

    while (!q.empty()) {

        str cur = q.front();
        q.pop();

        for (auto x : graph[cur]) {
            indegree[x]--;
            if (!indegree[x]) {
                q.push(x);
                result[cur].insert(x);
            }
        }
    }
}

int main() {

    setGraph();
    getFather();
    for (auto x : father) topologicalSort(x); //조상을 시작으로 위상정렬
    
    printf("%d\n", (int)father.size());
    for (auto x : father) printf("%s ", x.c_str());
    printf("\n");

    for (auto it=result.begin(); it!=result.end(); it++) {
        printf("%s %d ", it->X.c_str(), (int)(it->Y.size()));
        for (auto x : it->Y) printf("%s ", x.c_str());
        printf("\n");
    }
}