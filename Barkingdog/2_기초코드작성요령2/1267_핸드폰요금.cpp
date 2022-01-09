#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    int y = 0, m = 0;
    for (int i=0; i<N; i++) {
        int t;
        scanf("%d", &t);
        y += (t/30+1)*10;
        m += (t/60+1)*15;
    }

    if (y <= m) printf("Y ");
    if (y >= m) printf("M ");
    printf("%d", min(y, m));
    return 0;
}