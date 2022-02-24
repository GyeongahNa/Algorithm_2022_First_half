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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
long long tot;
vector<ii> jewel;
multiset<int> bag;

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++) {
        int m, v;
        scanf("%d %d", &m, &v);
        jewel.push_back({v, m});
    }
    sort(jewel.begin(), jewel.end());

    for (int i=0; i<K; i++) {
        int x;
        scanf("%d", &x);
        bag.insert(x);
    }

    for (int i=N-1; i>=0; i--) {
        auto pos = bag.lower_bound(jewel[i].Y);
        if (bag.empty() || pos == bag.end()) continue;
        tot += jewel[i].X;
        bag.erase(pos);
    } 
    printf("%lld", tot);
    return 0;
}