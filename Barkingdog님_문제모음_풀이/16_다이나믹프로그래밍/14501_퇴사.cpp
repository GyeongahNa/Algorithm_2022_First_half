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

//dp[i]: i번째 날까지 상담을 했을 때 최대수익(i번째 날 포함)

int N;
int T[20];
int P[20];
int dp[20];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d %d", &T[i], &P[i]);
    
    dp[1] = P[1];
    for (int i=2; i<=N+1; i++) {
        int mx = 0;
        for (int j=1; j<i; j++) {
            if (j+T[j]-1 < i) mx = max(mx, dp[j]);
        }
        dp[i] = mx+P[i];
    }

    printf("%d\n", dp[N+1]);
    return 0;
}