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

vector<bool> check(250001, true);
int dp[250001];

int main() {

    check[1] = false;
    for (int i=2; i*i<=250000; i++) {
        if (!check[i]) continue;
        for (int j=i*i; j<=250000; j+=i)
            check[j] = false;
    }

    for (int i=2; i<=250000; i++) {
        if (check[i]) dp[i] = dp[i-1]+1;
        else dp[i] = dp[i-1];
    }

    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", dp[2*n]-dp[n]);
    }
    return 0;
}