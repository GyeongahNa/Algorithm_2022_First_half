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
int num[2005];
int M;
int dp[2005][2005];

//dp[i][j]: num[i:j+1]의 회문 여부

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &num[i]);

    for (int i=0; i<N; i++) {
        dp[i][i] = 1;
        if (i+1 < N && num[i] == num[i+1]) dp[i][i+1] = 1;
    }   

    for (int j=2; j<N; j++) {
        int tmp = j;
        for (int i=0; i<N; i++) {
            if (tmp >= N) break;
            if (num[i] == num[tmp] && dp[i+1][tmp-1]) dp[i][tmp] = 1;
            tmp++;
        }
    }

    scanf("%d", &M);
    while (M--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", dp[x-1][y-1]);
    }
    return 0;
}