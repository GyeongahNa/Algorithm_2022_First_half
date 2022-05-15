#include <cstdio>
#include <cstring>
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

int N;
string s;
vector<int> dp(1010, INT_MAX);
map<char, char> m = {{'B', 'J'}, {'O', 'B'}, {'J', 'O'}};


int main() {

    cin >> N >> s;
    s = ' '+s;

    dp[1] = 0;
    for (int i=2; i<=N; i++) {
        for (int j=1; j<i; j++) {
            if (s[j] != m[s[i]] || dp[j] == INT_MAX) continue;
            dp[i] = min(dp[i], dp[j]+(i-j)*(i-j));
        }
    }

    if (dp[N] == INT_MAX) cout<<-1;
    else cout<<dp[N];
    return 0;
}