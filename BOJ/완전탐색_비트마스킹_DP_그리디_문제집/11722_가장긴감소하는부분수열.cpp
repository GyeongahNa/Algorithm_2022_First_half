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

int N, ret;
int A[1005];
int dp[1005];

int main() {

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];

    dp[1] = 1; ret = dp[1];
    for (int i=2; i<=N; i++) {
        dp[i] = 1;
        for (int j=1; j<i; j++) {
            if (A[j] <= A[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
        ret = max(ret, dp[i]);
    }
    cout<<ret;
    return 0;
}