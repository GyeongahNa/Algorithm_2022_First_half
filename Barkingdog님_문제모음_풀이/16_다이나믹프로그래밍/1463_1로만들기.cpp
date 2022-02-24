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

//dp[i]: i를 1로 만들기 위해 사용해야 하는 최소 연산 횟수
//dp[i] = min(dp[i/3], dp[i/2], dp[i-1])+1

int N;
int dp[1000001];

int main() {

    scanf("%d", &N);

    for (int i=2; i<=N; i++) {
        dp[i] = dp[i-1];
        if (!(i%3)) dp[i] = min(dp[i], dp[i/3]);
        if (!(i%2)) dp[i] = min(dp[i], dp[i/2]);
        dp[i]++;
    }
    printf("%d", dp[N]);
    return 0;
}
