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

int N, M;
vector<int> v;

int twoPointer() {

    int st = 0;
    int en = 1;
    int tot = v[0];
    int cnt = 0;

    while (st < N) {

        while (en < N && tot < M) {
            tot += v[en];
            en++;
        }
        if (tot == M) cnt++;
        tot -= v[st];
        st++;
    }
    return cnt;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    printf("%d", twoPointer());
    return 0;
}