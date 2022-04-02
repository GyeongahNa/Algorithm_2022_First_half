#include <cstdio>
#include <cstring>
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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int t[505], re[505];
int indegree[505];
vector<vector<int>> graph(505, vector<int>(0));

void getInput() {

    for (int i=1; i<=N; i++) {
        cin >> t[i]; 
        re[i] = t[i];
        while (1) {
            int x;
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i);
            indegree[i]++;
        }
    }
}

void topologicalSort() {

    queue<int> q;
    
    for (int i=1; i<=N; i++) {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!indegree[next]) continue;
            indegree[next]--;
            re[next] = max(re[next], re[cur]+t[next]);
            if (!indegree[next]) q.push(next);
        }
    }
}

int main() {

    cin >> N;
    getInput();
    topologicalSort();
    
    for (int i=1; i<=N; i++) cout<<re[i]<<"\n";
    return 0;
}