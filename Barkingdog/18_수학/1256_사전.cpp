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
#define mx 1000000000


long long N, M, K;
long long dp[105][105]; 
string ans = "";


void setdp() {

    for (long long i=0; i<=M; i++) dp[0][i] = 1;
    for (long long i=0; i<=N; i++) dp[i][0] = 1;
    for (long long i=1; i<=N; i++) {
        for (long long j=1; j<=M; j++) {
            if (dp[i-1][j] > mx-dp[i][j-1]) dp[i][j] = mx+1;
            else dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
}


void func(long long N, long long M, long long K) { 

    if (N == 0) {
        for (long long i=0; i<M; i++) ans += 'z';
        return ;
    }

    if (M == 0) {
        for (long long i=0; i<N; i++) ans += 'a';
        return ;
    }

    if (K <= dp[N-1][M]) {
        ans += "a";
        func(N-1, M, K);
    }
    else {
        ans += "z";
        func(N, M-1, K-dp[N-1][M]);
    }

}


int main() {

    scanf("%lld %lld %lld", &N, &M, &K);
    setdp();

    if (K > dp[N][M]) {
        printf("-1");
        return 0;
    }

    func(N, M, K);
    printf("%s", ans.c_str());
    return 0;
}

/*
dp[i][j]: 'a'를 i개, 'z'를 j개 나열하는 방법의 수
func(N, M, K): 'a'가 N개, 'z'가 M개 있을 때 K번째 문자열 구하기
*/