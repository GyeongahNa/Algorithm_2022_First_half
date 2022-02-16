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


long long N, A, B, C, D;
long long mn = __LONG_LONG_MAX__;


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


long long lcm(long long a, long long b) {
    return a/gcd(a, b)*b;
}


int main() {

    scanf("%lld %lld %lld %lld %lld", &N, &A, &B, &C, &D);

    if (B*C < A*D) {
        swap(A, C);
        swap(B, D);
    }
    
    long long l = lcm(A, C);
    for (long long i=0; A*i<l; i++) {
        long long p = i*B+((N-A*i)+C-1)/C*D;
        mn = min(mn, p);
    }
    printf("%lld", mn);
    return 0;
}

/*
만약 A를 이용하여 A와 C의 최소공배수 만큼을 구매하는 것보다
C를 이용하여 A와 C의 최소공배수 만큼을 구매하는 것이 더 싸다면,
A개짜리 묶음을 lcm(A, C)/A 이상 구매할 이유가 없음
(C짜리 묶음을 이용하여 lcm(A, B) 만큼을 구매하면 되기 때문)
*/