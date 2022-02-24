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

int T, K;

int main() {

    scanf("%d", &T);
    while (T--) {
        
        scanf("%d", &K);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        while (K--) {
            int x;
            scanf("%d", &x);
            pq.push(x);
        }
        
        long long tot = 0;
        while (pq.size() > 1) {
            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();
            tot += (f+s);
            pq.push(f+s);
        }
        printf("%lld\n", tot);
    }
    return 0;
}