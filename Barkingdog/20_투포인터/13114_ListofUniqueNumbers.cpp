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

int N;
vector<int> v;
vector<bool> check(100005, false);

long long twoPointer() {

    int st = 0;
    int en = 1;
    long long cnt = 0;
    check[v[0]] = true;

    while (st < N) {
        while (en < N && !check[v[en]]) {
            check[v[en]] = true;
            en++;
        }
        cnt += en-st;
        check[v[st]] = false;
        st++;
    }
    return cnt;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    printf("%lld", twoPointer());
    return 0;
}