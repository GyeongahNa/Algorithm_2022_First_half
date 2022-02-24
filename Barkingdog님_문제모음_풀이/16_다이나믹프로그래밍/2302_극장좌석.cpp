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

//dp[i][j]: i번째 자리에 j가 앉는 경우의 수

int N;
int M;
int dp[45];
bool fix[45];

int main() {

    scanf("%d\n%d\n", &N, &M);
    for (int i=0; i<M; i++) {
        int x;
        scanf("%d", &x);
        fix[x] = true;
    }

    dp[1] = 1; dp[2] = (fix[1] || fix[2]) ? 1 : 2; 
    for (int i=3; i<=N; i++) {
        if (fix[i] || fix[i-1]) dp[i] = dp[i-1];
        else dp[i] = dp[i-1]+dp[i-2];
    }

    printf("%d", dp[N]);
    return 0;
}