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


int a, b, c, d;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    scanf("%d %d\n%d %d", &a, &b, &c, &d);

    int A = a*d+b*c;
    int B = b*d;
    int g = gcd(A, B);
    printf("%d %d", A/g, B/g);
    return 0;
}