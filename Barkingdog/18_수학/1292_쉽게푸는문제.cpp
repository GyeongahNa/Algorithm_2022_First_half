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

int A, B;
int pfx[10000];

int main() {

    scanf("%d %d", &A, &B);

    int idx = 1, re = 0;
    for (int i=1; i<=100; i++) {
        for (int j=0; j<i; j++) {
            re += i;
            pfx[idx++] = re;
        }
    }

    printf("%d", pfx[B]-pfx[A-1]);
    return 0;
}