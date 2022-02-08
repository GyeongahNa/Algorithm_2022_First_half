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

int N;
int dp[100005];
int mn;

int main() {

    scanf("%d", &N);

    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        int mn = dp[i-1];
        for (int j=2; j*j<=i; j++) 
            mn = min(mn, dp[i-j*j]);
        dp[i] = mn+1;
    }
    
    printf("%d", dp[N]);
    return 0;
}