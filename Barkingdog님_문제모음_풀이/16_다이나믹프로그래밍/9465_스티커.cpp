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

//dp[0][j]: j번째 열의 스티커를 아무것도 떼어내지 않았을 때 최대 점수
//dp[1][j]: j번째 열의 스티커 중 위의 것을 떼어냈을 때 최대 점수
//dp[2][j]: j번째 열의 스티커 중 아래 것을 떼어냈을 때 최대 점수

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        
        int n;
        scanf("%d", &n);

        int score[2][100005];
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++)
                scanf("%d", &score[i][j]);
        }

        int dp[3][100005];
        dp[0][0] = 0;
        dp[1][0] = score[0][0];
        dp[2][0] = score[1][0];

        for (int i=1; i<n; i++) {
            dp[0][i] = max({dp[0][i-1], dp[1][i-1], dp[2][i-1]});
            dp[1][i] = max(dp[0][i-1], dp[2][i-1])+score[0][i];
            dp[2][i] = max(dp[0][i-1], dp[1][i-1])+score[1][i];
        }

        printf("%d\n", max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}));
    }
    return 0;
}