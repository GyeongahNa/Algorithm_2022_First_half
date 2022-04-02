#include <cstdio>
#include <cmath>
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

int N, L, R, x, cnt;
int A[20];
int t[20];

void combination(int k) {

    if (k >= 2) {
        int sum = 0, mx = 0, mn = INT_MAX;
        for (int i=0; i<k; i++) {
            mx = max(mx, A[t[i]]);
            mn = min(mn, A[t[i]]);
            sum += A[t[i]];
        }
        if (sum >= L && R >= sum && mx-mn >= x) cnt++;
    }

    if (k == N) return ;

    int st = 0;
    if (k != 0) st = t[k-1]+1;
    for (int i=st; i<N; i++) {
        t[k] = i;
        combination(k+1);
    }
}

int main() {

    cin >> N >> L >> R >> x;
    for (int i=0; i<N; i++) cin >> A[i];

    combination(0);
    cout<<cnt;
    return 0;
}