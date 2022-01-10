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

/* 재귀는 절차적이 아니라 귀납적으로 생각하기*/

long long func(int A, int B, int C) {
    if (B == 1) return A % C;
    if (B % 2 == 0) return func(A, B/2, C) * func(A, B/2, C) % C;
    return (func(A, B/2, C) * func(A, B/2, C) % C) * A % C;
}

int main() {

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%lld", func(A, B, C));
    return 0;
}