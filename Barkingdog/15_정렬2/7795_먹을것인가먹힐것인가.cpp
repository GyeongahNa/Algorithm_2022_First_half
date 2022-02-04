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

int T;
int N, M;
int A[20001], B[20001]; 

int cntEaten() {

    int i = 0, j = 0, cnt = 0;
    while (i < N) {
        while (j < M && B[j] < A[i]) j++;
        cnt += j;
        i++;
    }
    return cnt;
}

int main() {

    scanf("%d", &T);
    while (T--) {

        scanf("%d %d", &N, &M);
        for (int i=0; i<N; i++)
            scanf("%d", &A[i]);
        for (int i=0; i<M; i++)
            scanf("%d", &B[i]);

        stable_sort(A, A+N);
        stable_sort(B, B+M);
        printf("%d\n", cntEaten());
    }
    return 0;
}