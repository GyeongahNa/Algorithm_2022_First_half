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

int T, M, N, x, y;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    if (a < b) swap(a, b);
    return a/gcd(a, b)*b;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int L = lcm(M, N);
        bool check = false;
        for (int k=x-1; k<L; k+=M) {
            if (k%N == y-1) {
                printf("%d\n", k+1);
                check = true;
                break;
            }
        }
        if (!check) printf("%d\n", -1);
    }
    return 0;
}

/*연립합동방정식*/