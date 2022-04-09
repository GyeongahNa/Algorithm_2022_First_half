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

string s1, s2;
int dp[1005][1005];

int main() {

    cin >> s1 >> s2;
    s1 = ' '+s1;
    s2 = ' '+s2;

    for (int i=1; i<s1.size(); i++) {
        for (int j=1; j<s2.size(); j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<s1.size()+s2.size()-dp[s1.size()-1][s2.size()-1]-2;
    return 0;
}