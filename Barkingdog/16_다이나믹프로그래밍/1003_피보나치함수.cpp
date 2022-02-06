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

//dp1[i]: fibonacci(i)를 호출했을 때 출력되는 0의 개수
//dp2[i]: fibonacci(i)를 호출했을 때 출력되는 1의 개수

int T;
int dp1[45];
int dp2[45];

int main() {

    dp1[0] = 1; dp1[1] = 0;
    dp2[0] = 0; dp2[1] = 1;
    for (int i=2; i<=40; i++) {
        dp1[i] = dp1[i-1]+dp1[i-2];
        dp2[i] = dp2[i-1]+dp2[i-2];
    }

    scanf("%d", &T);
    while (T--) {
        int x;
        scanf("%d", &x);
        printf("%d %d\n", dp1[x], dp2[x]);
    }
    return 0;
}