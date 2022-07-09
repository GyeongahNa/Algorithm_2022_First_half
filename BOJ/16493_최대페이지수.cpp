#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
vector<ii> v;
int dp[30][205];

int main() {

    cin >> N >> M;
    v.resize(M);
    for (int i=0; i<M; i++) cin >> v[i].X >> v[i].Y;
    
    int mx = 0;
    if (N >= v[0].X) mx = v[0].Y;

    dp[0][v[0].X] = v[0].Y;
    for (int i=1; i<M; i++) {
        for (int j=0; j<=N; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-v[i].X >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i].X]+v[i].Y);
            mx = max(mx, dp[i][j]);
        }
    }
    cout<<mx;
    return 0;
}   