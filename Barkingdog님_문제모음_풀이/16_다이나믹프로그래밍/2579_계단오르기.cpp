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

//dp[i]: i번째 칸에 도착하였을 때 얻을 수 있는 최대 점수
//dp[i] = max(dp[i-2]+v[i], dp[i-3]+v[i-1]+v[i])

int N;
int v[305];
int dp[305];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++) 
        scanf("%d", &v[i]);
    
    dp[1] = v[1]; 
    dp[2] = v[1]+v[2]; 

    for (int i=3; i<=N; i++)
        dp[i] = max(dp[i-2]+v[i], dp[i-3]+v[i-1]+v[i]);
    printf("%d", dp[N]);
    return 0;
}