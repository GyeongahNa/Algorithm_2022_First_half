#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

long long N;
vector<long long> v, vret;

bool isPrime(long long n) {

    if (n <= 1) return false;
    for (long long i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void split() {

    long long k = 2, tmp = N;
    while (N != 1 && k*k <= tmp) {

        while (N%k == 0) {
            N /= k;
            v.push_back(k);
        }
        
        if (k == 2) k++;
        else k += 2;
    }
    
    if (N != 1) v.push_back(N);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    if (isPrime(N)) {
        cout<<-1;
        return 0;
    }

    split();

    long long sz = v.size();
    for (long long i=0; i<sz/2; i++) vret.push_back(v[i*2]*v[i*2+1]);
    if (sz%2) vret.back() *= v.back();
    for (auto x : vret) cout<<x<<" ";
    return 0;
}

/* 어떤수 x를 소인수분해하여 두개씩 곱하면 합성수분해의 결과가 됨
(소인수분해 한 결과가 홀수개 일 경우, 마지막 원소는 합성수분해 결과의 가장 마지막 원소에 곱함)
*/