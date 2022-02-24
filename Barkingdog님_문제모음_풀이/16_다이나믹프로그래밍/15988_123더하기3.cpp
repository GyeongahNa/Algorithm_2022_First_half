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
#define mod 1000000009

//dp[i] = i를 1,2,3의 합으로 나타내는 방법의 수
//dp[i] = dp[i-1]+dp[i-2]+dp[i-3]

int T;
int dp[1000001];

int main() {

    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i=4; i<=1000000; i++)
        dp[i] = ((dp[i-1]+dp[i-2])%mod+dp[i-3])%mod;

    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", dp[x]);
    }
    return 0;
}