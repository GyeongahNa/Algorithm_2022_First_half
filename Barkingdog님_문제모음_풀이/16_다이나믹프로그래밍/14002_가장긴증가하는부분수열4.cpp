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

int N;
int A[1005];
int dp[1005];
int pre[1005];
int ansidx, ansval;

void dinamic() {

    ansidx = 0, ansval = 1;
    for (int i=0; i<N; i++) {
        dp[i] = 1;
        pre[i] = -1;
        for (int j=0; j<i; j++) {
            if (A[j] < A[i] && dp[j]+1>dp[i]) {
                dp[i] = dp[j]+1;
                pre[i] = j;
            }
        }
        if (ansval < dp[i]) {
            ansidx = i;
            ansval = dp[i];
        }
    }
}

void tracking() {

    stack<int> st;
    while (1) {
        st.push(A[ansidx]);
        ansidx = pre[ansidx];
        if (ansidx == -1) break;
    }
    while (!st.empty()) {
        printf("%d ", st.top()); 
        st.pop();
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);
    
    dinamic();
    printf("%d\n", ansval);
    tracking();
    return 0;
}