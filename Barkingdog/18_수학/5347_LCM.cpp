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

int N, a, b;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a,b)*b;
}

int main() {

    scanf("%d", &N);
    while (N--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a, b));
    }
    return 0;
}