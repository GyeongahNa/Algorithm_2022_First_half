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
int A[100005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) 
        scanf("%d", &A[i]);
    sort(A, A+N);

    int mx = 0;
    for (int i=1; i<=N; i++)
        mx = max(mx, A[N-i]*i);
    printf("%d", mx);
    return 0;
} 