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
#include <climits>
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

int T, N, M;
int dp[10005];

void dynamic(const vector<int>& c) {

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (j < c[i]) continue;
            dp[j] += dp[j-c[i]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> c(N+1, 0);
        for (int i=1; i<=N; i++) cin >> c[i];
        cin >> M;
        dynamic(c);
        cout<<dp[M]<<"\n";
    }
    return 0;
}