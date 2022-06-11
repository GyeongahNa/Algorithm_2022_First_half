#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

#define X first
#define Y second

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        cin >> N;
        if (!N) break;

        vi v(N+1, 0);
        vvi dp(N+1, vi(2, INT_MIN));
        
        for (int i=1; i<=N; i++) {
            cin >> v[i];
            if (i == 1) {
                dp[i][1] = v[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1]+v[i], v[i]);
        }
        cout<<max(dp[N][0], dp[N][1])<<"\n";
    }
    return 0;
}