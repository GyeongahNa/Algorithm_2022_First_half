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

//dp[i]: i번째 돌을 상근이가 마지막으로 가져가는지 여부
//dp[i] = (!dp[i-4] || !dp[i-3] || !dp[i-1]) ? 1 : 0;

int N;
int dp[1005];

int main() {

    scanf("%d", &N);    
    dp[1] = 1; dp[2] = 0; dp[3] = 1; dp[4] = 1;

    for (int i=5; i<=N; i++)
        dp[i] = (!dp[i-4] || !dp[i-3] || !dp[i-1]) ? 1 : 0;
    
    if (dp[N]) printf("SK");
    else printf("CY");
    return 0;
}