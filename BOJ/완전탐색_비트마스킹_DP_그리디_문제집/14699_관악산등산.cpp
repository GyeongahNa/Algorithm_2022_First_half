#include <cstdio>
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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
vector<int> h(5005, 0);
vector<int> memo(5005, 0);
vector<vector<int>> graph(5005, vector<int>(0));

int dfs(int x) {

    if (memo[x]) return memo[x];
    
    memo[x] = 1;
    for (int i=0; i<graph[x].size(); i++) {
        int next = graph[x][i];
        if (h[x] >= h[next]) continue;
        memo[x] = max(memo[x], dfs(next)+1);
    }
    return memo[x];
}

int main() {

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> h[i];
    for (int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for (int i=1; i<=N; i++) 
        cout<<dfs(i)<<endl;
    return 0;
}