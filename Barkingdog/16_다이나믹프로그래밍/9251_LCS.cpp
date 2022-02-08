#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

//dp[i][j]: s2를 i번째 인덱스까지, s1을 j번째 인덱스까지 사용하였을 때 LCS
// (if s2[i] == s1[j]) dp[i][j] = dp[i-1][j-1]+1;
// (if s2[i] != s1[j]) dp[i][j] = max(dp[i][j-1], dp[i-1][j])

int dp[1005][1005];
string s1, s2;

int main() {

    char str1[1005], str2[1005];
    scanf("%s\n%s", str1, str2);
    s1 = str1; s1 = " "+s1;
    s2 = str2; s2 = " "+s2;

    int sz1 = s1.size(), sz2 = s2.size();

    int ans = 0;
    for (int i=1; i<sz2; i++) {
        for (int j=1; j<sz1; j++) {
            if (s2[i] == s1[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}