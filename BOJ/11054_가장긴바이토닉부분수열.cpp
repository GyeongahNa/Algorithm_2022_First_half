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

int N, ans;
vector<int> v;
vector<vector<int>> dp(1005, vector<int>(2, 1));

int main() {

    cin >> N;
    v.resize(N);
    for (auto& x : v) cin >> x;

    for (int i=0; i<N; i++) {

        for (int j=0; j<i; j++) {
            if (v[j] >= v[i]) continue;
            dp[i][0] = max(dp[i][0], dp[j][0]+1);
        }

        for (int j=0; j<i; j++) {
            if (v[j] <= v[i]) continue;
            dp[i][1] = max(dp[i][1], dp[j][0]+1);
            dp[i][1] = max(dp[i][1], dp[j][1]+1);
        }
        ans = max({ans, dp[i][0], dp[i][1]});
    }

    cout<<ans;
    return 0;
}