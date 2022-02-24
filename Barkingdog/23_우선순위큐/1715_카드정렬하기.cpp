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

int N, x;
long long tot;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &x);   
        pq.push(x);
    }

    if (N < 2) {
        printf("0\n");
        return 0;
    }
 
    while (pq.size() > 1) {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        tot += (f+s);
        pq.push(f+s);
    }

    printf("%lld", tot);
    return 0;
}