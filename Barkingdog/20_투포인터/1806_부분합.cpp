#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, S;
vector<int> v;

int twoPointer() {

    int st = 0;
    int en = 1;
    int tot = v[0];
    int mn = INT_MAX;

    while (st < N) {
        while (en < N && tot < S) {
            tot += v[en];
            en++;
        }
        if (tot >= S) mn = min(mn, en-st);
        tot -= v[st];
        st++;
    }
    if (mn == INT_MAX) return 0;
    return mn;
}

int main() {

    scanf("%d %d", &N, &S);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    printf("%d", twoPointer());
    return 0;
}