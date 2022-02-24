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


int N, f, r, l;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int main() {

    scanf("%d", &N);
    scanf("%d", &f);

    for (int i=1; i<N; i++) {
        scanf("%d", &r);
        l = lcm(f, r);
        printf("%d/%d\n", l/r, l/f);
    }
    return 0;
}