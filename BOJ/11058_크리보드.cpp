#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
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

int N;
long long dp[105];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        dp[i] = dp[i-1]+1;
        for (int j=i-1; j>=3; j--) {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        } 
    }
    cout<<dp[N];
    return 0;
}