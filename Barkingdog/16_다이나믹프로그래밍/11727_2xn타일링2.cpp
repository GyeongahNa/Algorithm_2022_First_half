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

//dp[i]: 2*i 크기의 직사각형을 타일로 채우는 방법의 수
//dp[i] = dp[i-1]+dp[i-2]*2;

int N;
int dp[1005];

int main() {

    scanf("%d", &N);
    
    dp[1] = 1; dp[2] = 3;
    for (int i=3; i<=N; i++)
        dp[i] = (dp[i-1]+2*dp[i-2])%10007;
    printf("%d\n", dp[N]);
    return 0;
}