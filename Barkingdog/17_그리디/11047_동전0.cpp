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

int N, K;
int C[15];

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++)
        scanf("%d", &C[i]);

    int cnt = 0;
    for (int i=N-1; i>=0; i--) {
        if (C[i] > K) continue;
        cnt += K/C[i];
        K -= K/C[i]*C[i];
    }
    printf("%d", cnt++);
    return 0;
}