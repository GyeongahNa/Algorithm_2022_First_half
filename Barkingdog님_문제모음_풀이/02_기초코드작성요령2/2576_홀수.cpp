#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    int n, sum = 0, m = 101;
    for (int i=0; i<7; i++) {
        scanf("%d", &n);
        if (n%2 == 0) continue;
        sum += n;
        m = min(m, n);
    }
    if (sum == 0) printf("-1");
    else printf("%d\n%d", sum, m);
    return 0;
}