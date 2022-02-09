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

//dp[i][1]: 상근이가 i번째 돌까지 연속으로 1개의 돌을 골라 이길 수 있는지의 여부
//dp[i][3]: 상근이가 i번째 돌까지 연속으로 3개의 돌을 골라 이길 수 있는지의 여부

int N;
int dp[1005][4];

int main() {

    scanf("%d", &N);

    dp[1][1] = 1;
    dp[3][1] = 1;
    dp[3][3] = 1;
    
    for (int i=5; i<=N; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][3]);
        dp[i][3] = max(dp[i-4][1], dp[i-4][3]);
    }

    if (max(dp[N][1], dp[N][3])) printf("SK");
    else printf("CY");
    return 0;
}

/*오버플로우 때문에 헤맸던 문제*/