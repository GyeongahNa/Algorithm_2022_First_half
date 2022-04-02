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
#define mod 1000000000

int N, K;
int dp[205][205];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for (int i=0; i<=K; i++) dp[0][i] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            for (int k=0; k<=i; k++) dp[i][j] = (dp[i][j]+dp[i-k][j-1])%mod;
        }
    }

    cout<<dp[N][K];
    return 0;
}