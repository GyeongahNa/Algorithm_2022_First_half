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

int T, N;

int main() {

    cin >> T;
    while (T--) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);

        cin >> N;
        vector<int> v(N, 0), sum(N, 0);
        vector<vector<int>> dp(N, vector<int> (N, INT_MAX));
        for (auto& x : v) cin >> x;

        sum[0] = v[0];
        for (int i=1; i<N; i++) sum[i] = sum[i-1]+v[i];

        for (int k=0; k<N; k++) {
            for (int i=0; i<N; i++) {
                if (i+k >= N) continue;
                if (k == 0) dp[i][i+k] = 0;
                else if (k == 1) dp[i][i+k] = v[i]+v[i+k];
                else {
                    for (int mid = i; mid<i+k; mid++) dp[i][i+k] = min(dp[i][i+k], dp[i][mid]+dp[mid+1][i+k]);
                    dp[i][i+k] += (i == 0 ? sum[i+k] : sum[i+k]-sum[i-1]);
                }
            }
        }

        cout<<dp[0][N-1]<<"\n";
    }
    return 0;
}
