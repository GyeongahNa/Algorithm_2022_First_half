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


int N;
long long arr[1000005];
long long p10[14];

long long reverse(long long x) {

    int cnt = 0;
    long long tmp = x;
    while (tmp) {
        cnt++;
        tmp /= 10;
    }

    long long re = 0;
    while (--cnt >= 0) {
        re += (x%10)*p10[cnt];
        x /= 10;
    }
    return re;
}

int main() {

    scanf("%d", &N);

    p10[0] = 1;
    for (int i=1; i<14; i++) p10[i] = p10[i-1]*10;

    for (int i=0; i<N; i++) {
        long long x;
        scanf("%lld", &x);
        arr[i] = reverse(x);
    }
    sort(arr, arr+N);

    for (int i=0; i<N; i++)
        printf("%lld\n", arr[i]);
    return 0;
}