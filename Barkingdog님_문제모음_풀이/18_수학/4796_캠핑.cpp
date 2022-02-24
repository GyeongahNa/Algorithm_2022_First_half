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

int L, P, V;

int main() {

    int idx = 1;
    while (1) {
        scanf("%d %d %d", &L, &P, &V);
        if (L == 0 || P == 0 || V == 0) break;
        printf("Case %d: %d\n", idx++, V/P*L+min(V%P, L));
    }
    return 0;
}