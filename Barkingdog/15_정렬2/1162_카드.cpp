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
long long arr[100005];

long long getMaxNum() {

    long long maxcnt = 0;
    long long maxnum = 0;
    
    int idx = 0;
    while (idx < N) {
        long long num = arr[idx], cnt = 0;
        while (idx < N && arr[idx] == num) {
            idx++;
            cnt++;
        }
        if (maxcnt < cnt) {
            maxcnt = cnt;
            maxnum = num;
        }
    }
    return maxnum;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%lld", &arr[i]);
    
    sort(arr, arr+N);
    printf("%lld", getMaxNum());
    return 0;
}