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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<long long> v;
vector<bool> check(4000005, true);

void eratosthenes() {

    check[1] = false;
    for (long long i=2; i<=N; i++) {
        if (!check[i]) continue;
        for (long long j=i*i; j<=N; j+=i) 
            check[j] = false;
        v.push_back(i);
    }
}

int twoPointer() {

    int st = 0;
    int en = 1;
    int sz = v.size();
    long long tot = v[0]; 
    long long cnt = 0;

    while (st < sz) {
        while (en < sz && tot < N) {
            tot += v[en];
            en++;
        }
        if (tot == N) cnt++;
        tot -= v[st];
        st++;
    }
    return cnt;
}

int main() {

    scanf("%d", &N);
    eratosthenes();
    if (v.size() < 1) printf("0"); //예외처리
    else printf("%d", twoPointer());
    return 0;
}