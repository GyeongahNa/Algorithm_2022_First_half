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

int T, N;
vector<bool> vcheck(10005, true);

int main() {

    for (int i=2; i*i<=10000; i++) {
        if (!vcheck[i]) continue;
        for (int j=i*i; j<=10000; j+=i)
            vcheck[j] = false;
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i=N/2; i>=2; i--) {
            if (vcheck[i] && vcheck[N-i]) {
                printf("%d %d\n", i, N-i);
                break;
            }
        }
    }
    return 0;
}