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

long long N;
long long arr[15];
long long p10[15];
vector<long long> v;
int cnt;

void func(int k) {

    if (k >= 1 && 10 >= k) {
        long long num = 0;
        for (long long i=k-1; i>=0; i--)
            num += arr[i]*p10[k-1-i];
        v.push_back(num);
    }

    long long st = 9;
    if (k != 0) st = arr[k-1]-1;
    for (long long i=st; i>=0; i--) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {

    //10의 제곱수 구해놓기
    p10[0] = 1;
    for (long long i=1; i<=10; i++)
        p10[i] = p10[i-1]*10;

    //백트래킹으로 감소하는 수 구하기
    func(0);
    sort(v.begin(), v.end());

    //N번째 감소하는 수 구하기
    scanf("%lld", &N);
    if (N >= v.size()) printf("-1");
    else printf("%lld", v[N]);
    return 0;
}