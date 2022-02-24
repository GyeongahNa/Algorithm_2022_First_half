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

long long A, B, cnt;
long long N = 10000000;
vector<bool> vcheck(10000005, true);

int main() {

    scanf("%lld %lld", &A, &B);

    vcheck[1] = false;
    for (long long i=2; i*i<=N; i++) {
        if (!vcheck[i]) continue;
        for (long long j=i*i; j<=N; j+=i)
            vcheck[j] = false;
    }

    for (long long i=2; i<=N; i++) {
        if (!vcheck[i]) continue;
        for (long long j=i; j<=B/i; j*=i) { 
            if (j*i >= A) cnt++;
        }
    }    
    printf("%lld", cnt);
    return 0;
}

/*
line 35
for (long long j=i*i; j<=B; j*=i) {
    if (j >= A) cnt++;
}
와 같이 구현할 경우 i=10^7일 때 long long 오버플로우 발생
*/
