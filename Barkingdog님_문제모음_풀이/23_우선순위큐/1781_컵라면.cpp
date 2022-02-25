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

int N;
vector<ii> v;
priority_queue<int> pq;


int main() {

    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int d, n;
        scanf("%d %d", &d, &n);
        v.push_back({d, n});
    }
    sort(v.begin(), v.end());

    int idx = N-1;
    long long cnt = 0;
    for (int i=N; i>0; i--) {
        while (idx >= 0 && v[idx].X == i) pq.push(v[idx--].Y);
        if (!pq.empty()) {
            cnt += pq.top();
            pq.pop();
        }
    }
    printf("%lld\n", cnt);
    return 0;
}