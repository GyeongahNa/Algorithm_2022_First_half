#include <cstdio>
#include <cstring>
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

//dp[i][j]: i번째 행 j번째 열에 도착하기 까지의 최대 합
//dp[i][j] = v[i][j]+max(dp[i-1][j], dp[i-1][j-1])

int N;
vector<int> v[505];
int dp[505][505];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        for (int j=0; j<i; j++) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
        }
    }

    dp[1][0] = v[1][0];
    for (int i=2; i<=N; i++) {
        for (int j=0; j<i; j++) {
            if (j == 0) dp[i][j] = v[i][j]+dp[i-1][j];
            else if (j == i-1) dp[i][j] = v[i][j]+dp[i-1][j-1];
            else dp[i][j] = v[i][j]+max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    printf("%d\n", *max_element(dp[N], dp[N]+N));
    return 0;
}