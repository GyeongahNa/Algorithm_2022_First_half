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

int N;
vector<ii> v;
vector<vector<int>> dp(505, vector<int>(505, INT_MAX));

int main() {

    cin >> N;
    v.resize(N);
    for (auto& [x, y] : v) { cin >> x; cin >> y; }

    for (int k=0; k<N; k++) {
        
        for (int i=0; i<N; i++) {
            if (i+k >= N) continue;
            if (k == 0) dp[i][i+k] = 0;
            else if (k == 1) dp[i][i+k] = (v[i].X * v[i].Y * v[i+k].Y);
            else  {
                for (int mid=i; mid<i+k; mid++) {
                    int nop = dp[i][mid]+dp[mid+1][i+k] + v[i].X*v[mid].Y*v[i+k].Y;
                    dp[i][i+k] = min(dp[i][i+k], nop);
                }
            }
        }
    }

    cout<<dp[0][N-1];
    return 0;
}