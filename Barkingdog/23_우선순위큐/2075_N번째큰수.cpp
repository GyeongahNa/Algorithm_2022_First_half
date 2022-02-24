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
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using str = string;

#define X first
#define Y second

int N, K;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N*N; i++) {
        int x;
        scanf("%d", &x);
        pq.push(x);
        while (pq.size() > N) {
            pq.pop();
        }
    }

    printf("%d\n", pq.top());
    return 0;
}