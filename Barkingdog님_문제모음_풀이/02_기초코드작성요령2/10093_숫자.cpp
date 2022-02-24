#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

    long long A, B;
    scanf("%lld %lld", &A, &B);
    
    int cnt = abs(A-B)-1;
    printf("%d\n", cnt >= 0 ? cnt : 0);
    for (long long i=min(A, B)+1; i<max(A, B); i++)
        printf("%lld ", i);
    return 0;
}