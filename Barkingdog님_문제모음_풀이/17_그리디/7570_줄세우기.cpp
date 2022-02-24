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

int N;
int dp[1000005];

//dp[i]: i로 끝나는 가장 긴 연속된 증가하는 부분 수열의 길이
//dp[i] = dp[i-1]+1

int main() {

    scanf("%d", &N);

    int mx = 0;
    for (int i=0; i<N; i++) {
        int nchild;
        scanf("%d", &nchild);
        dp[nchild] = dp[nchild-1]+1;
        mx = max(dp[nchild], mx);
    }
    printf("%d", N-mx);
    return 0;
}