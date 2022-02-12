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
ii arr[100005];
int dp[100005];

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &arr[i].Y, &arr[i].X);
    sort(arr, arr+N);

    int t = 0, cnt = 0;
    for (int i=0; i<N; i++) {
        if (t > arr[i].Y) continue;
        cnt++;
        t = arr[i].X;
    }
    printf("%d", cnt);
    return 0;
}


//dp 풀이: O(N^2) 시간초과
/*
int N;
ii arr[100005];
int dp[100005];

int main() {

    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d %d", &arr[i].X, &arr[i].Y);
    sort(arr+1, arr+N+1);

    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        dp[i] = dp[i-1];
        for (int j=i-1; j>=0; j--) {
            if (arr[j].Y > arr[i].X) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
    }

    printf("%d", dp[N]);
    return 0;
}
*/