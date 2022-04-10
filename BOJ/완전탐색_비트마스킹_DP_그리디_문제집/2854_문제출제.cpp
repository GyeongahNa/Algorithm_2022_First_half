
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
#define mod 1000000007

int n;
long long a[100005], b[100005];
long long dp[100005][4];

int main() {

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<n; i++) cin >> b[i];

    dp[1][1] = a[1]; dp[1][2] = 0; dp[1][3] = b[1];

    for (int i=2; i<=n; i++) {
        dp[i][1] = ((dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) * a[i]) % mod;
        dp[i][2] = ((dp[i - 1][1] + dp[i - 1][2]) * b[i - 1] + dp[i - 1][3] * (b[i - 1] - 1)) % mod;
        dp[i][3] = ((dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) * b[i]) % mod;
    }

    cout<<(((dp[n][1]+dp[n][2])%mod)+dp[n][3])%mod;
    return 0;
}