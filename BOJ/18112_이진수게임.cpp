#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

int L, K;
string sl, sk;
vector<int> dist(10000, -1);

int bfs() {

    queue<int> q;
    q.push(L);
    dist[L] = 0;

    while (!q.empty()) {

        int cur = q.front();
        if (cur == K) return dist[K];
        q.pop();

        vector<int> vnx = {cur-1, cur+1};
        int idx = -1, tmp = cur;
        while (tmp) { idx++; tmp/=2; };
        for (int i=0; i<idx; i++) vnx.push_back(cur^(1<<i));
            
        for (auto nx : vnx) {
            if (nx < 0 || dist[nx] != -1) continue;
            q.push(nx);
            dist[nx] = dist[cur]+1;
        }
    }
    return -1;
}

int main() {

    cin >> sl >> sk;
    L = stoi(sl, 0, 2);
    K = stoi(sk, 0, 2);
    cout<<bfs();
    return 0;
}