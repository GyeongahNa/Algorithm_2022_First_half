#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int func(int N, int r, int c) {

    if (N == 0) return 0; //base condition

    int quad = 0;
    int half = 1<<(N-1); //int half = pow(2, N-1);
    if (r < half && c < half) quad = 0;
    else if (r < half && c >= half) quad = 1;
    else if (r >= half && c < half) quad = 2;
    else quad = 3;
 
    int nr = (r >= half) ? r-half : r;
    int nc = (c >= half) ? c-half : c;
    return quad*half*half + func(N-1, nr, nc);
}

int main() {

    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d", func(N, r, c));
    return 0;
}