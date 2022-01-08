#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int main() {

    int sum = 0;
    while (true) {

        int n;
        scanf("%d", &n);

        if (n == -1) break;
        sum += n;
    }
    printf("%d", sum);
    return 0;
}