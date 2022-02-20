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
int A[1000005];
int L[1000005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);

    int len = 0;
    for (int i=0; i<N; i++) {
        int pos = lower_bound(L, L+len, A[i])-L;
        L[pos] = A[i];
        if (pos == len) len++;
    }

    printf("%d", len);
    return 0;
}