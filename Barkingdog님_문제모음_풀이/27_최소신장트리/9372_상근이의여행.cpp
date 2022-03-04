#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T;
int N, M;
int a, b;

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        while (M--) scanf("%d %d", &a, &b);
        printf("%d\n", N-1);
    }
    return 0;
}