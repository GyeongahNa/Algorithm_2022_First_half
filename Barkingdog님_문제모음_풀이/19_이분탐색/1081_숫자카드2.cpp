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
#include <limits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define HALF 10000000

int N, M, x;
int A[20000001];


int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &x);
        A[x+HALF]++;
    }

    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &x);
        printf("%d ", A[x+HALF]);
    }
    return 0;
}