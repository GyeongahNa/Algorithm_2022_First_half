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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

bool isPrime(long long n) {
    
    if (n <= 1) return false;
    for (long long i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    
    //수 n을 k진수로 변환하여 문자열 s에 저장
    string s = "0";
    while (n) {
        s += n%k+'0';
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    //0으로 둘러쌓인 숫자가 소수인지 확인하여 카운트
    int cnt = 0;
    long long tmp = 0;
    for (auto c : s) {
        if (c != '0') tmp = tmp*10+c-'0';
        else {
            if (isPrime(tmp)) cnt++;
            tmp = 0;
        }
    }
    return cnt;
}