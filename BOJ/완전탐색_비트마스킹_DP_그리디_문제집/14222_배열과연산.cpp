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

int N, K;
vector<int> A(55, 0);
vector<int> node(55, 0);
vector<vector<int>> graph(55, vector<int>(0));

bool dfs(int x, vector<bool>& check) {

    for (int i=0; i<graph[x].size(); i++) {
        int t = graph[x][i];
        if (check[t]) continue;
        check[t] = true;

        if (!node[t] || dfs(node[t], check)) {
            node[t] = x;
            return true;
        }
    }
    return false;
}

int main() {

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i];

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (A[i] <= j && (j-A[i])%K == 0) graph[i].push_back(j);
        }
    }

    //이분매칭
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        vector<bool> check(55, 0);
        if (dfs(i, check)) cnt++;
    }

    if (cnt < N) cout<<0;
    else cout<<1;
    return 0;
}