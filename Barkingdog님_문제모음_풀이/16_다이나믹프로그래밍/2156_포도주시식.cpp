#include <cstdio>
#include <cstring>
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

//dp[i][j]: i번째 인덱스까지 연속으로 j개의 포도주를 마셨을 때 최대 양

int N;
int A[10005];
int dp[10005][3];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d", &A[i]);

    dp[1][0] = 0;
    dp[1][1] = A[1];
    dp[1][2] = A[1];

    for (int i=2; i<=N; i++) {
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = dp[i-1][0]+A[i];
        dp[i][2] = dp[i-1][1]+A[i];
    }

    printf("%d", max({dp[N][0], dp[N][1], dp[N][2]}));
    return 0;
}