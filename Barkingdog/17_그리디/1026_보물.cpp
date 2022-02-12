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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int A[55], B[55];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    for (int i=0; i<N; i++) scanf("%d", &B[i]);

    sort(A, A+N, greater<>());
    sort(B, B+N);

    int re = 0;
    for (int i=0; i<N; i++) re += A[i]*B[i];
    printf("%d", re);
    return 0;
}