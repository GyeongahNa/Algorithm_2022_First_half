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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int x;
int bit[(1<<25)/32+1];

int main() {

    while (scanf("%d", &x) != -1) {
        if (!(bit[x/32]&(1<<(x%32)))) {
            printf("%d ", x);
            bit[x/32] |= (1<<(x%32));
        }
    }
    return 0;
}