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
int dp[25][105];
int L[25], J[25];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i=1; i<=N; i++) cin >> L[i];
    for (int i=1; i<=N; i++) cin >> J[i];

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=100; j++) {
            dp[i][j] = dp[i-1][j];
            if (j+L[i] <= 100) dp[i][j] = max(dp[i][j], dp[i-1][j+L[i]]+J[i]);
        }
    }

    int mx = 0;
    for (int j=1; j<=100; j++) mx = max(mx, dp[N][j]);
    cout<<mx;
    return 0;
}

/*
dp[i][j]: i번째 사람까지 j만큼의 체력을 남기면서 인사했을 때 얻을 수 있는 최대 기쁨
*/