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

//dp[i]: 인덱스 0부터 인덱스 i까지의 원소들의 합
//i부터 j까지 원소의 합 = dp[j]-dp[i-1]

int N, M;
int arr[100005];
int dp[100005];

int main() {

    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    dp[1] = arr[1];
    for (int i=2; i<=N; i++)
        dp[i] = dp[i-1]+arr[i]; 
    
    while (M--) {
        int i, j;
        scanf("%d %d", &i, &j);
        printf("%d\n", dp[j]-dp[i-1]);
    }
    return 0;
}