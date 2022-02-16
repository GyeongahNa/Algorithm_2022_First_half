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

#define X first
#define Y second

long long N;
vector<bool> check(3000005, true);


void eratosthenes() {

    check[1] = false;
    for (long long i=2; i<=3000000; i++) {
        if (!check[i]) continue;
        for (long long j=i*i; j<=3000000; j+=i)
            check[j] = false;
    }
}


bool ispalindrome(int num) {

    string s = to_string(num);
    int sz = s.size();
    for (int i=0; i<sz/2; i++) {
        if (s[i] != s[sz-1-i]) return false;
    }
    return true;
}


int main() {

    eratosthenes();

    scanf("%lld", &N);
    for (long long i=N; i<=3000000; i++) {
        if (check[i] && ispalindrome(i)) {
            printf("%lld", i);
            break;
        }
    }
    return 0;
}