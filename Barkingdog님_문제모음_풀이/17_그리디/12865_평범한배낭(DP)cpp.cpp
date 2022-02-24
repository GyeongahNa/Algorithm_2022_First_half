#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

//dp[i][j]: 인덱스 i번까지 무게 j로 얻을 수 있는 최대 가치

int N, K;
ii arr[105];
int dp[105][100005];

int main() {

    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++)
        scanf("%d %d", &arr[i].X, &arr[i].Y);

    dp[0][arr[0].X] = arr[0].Y;
    for (int i=1; i<N; i++) {
        for (int j=1; j<=K; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= arr[i].X) 
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].X]+arr[i].Y);
        }
    }

    int re = 0;
    for (int i=0; i<=K; i++) re = max(re, dp[N-1][i]);
    printf("%d", re);
    return 0;
}