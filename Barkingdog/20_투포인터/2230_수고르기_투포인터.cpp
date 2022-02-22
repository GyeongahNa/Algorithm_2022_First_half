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
vector<int> A;

int twoPointer() {

    int st = 0;
    int en = 0;
    int mn = INT_MAX;

    while (st < N) {
        while (en < N && A[en]-A[st] < M) en++;
        if (en < N) mn = min(mn, A[en]-A[st]);
        st++;
    }
    return mn;
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    printf("%d ", twoPointer());
    return 0;
}