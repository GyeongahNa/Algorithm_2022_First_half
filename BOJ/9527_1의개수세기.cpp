#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

unsigned long long A, B;

string getBin(unsigned long long num) {

    string s = "";
    while (num) {
        s = char(num%2+'0')+s;
        num /= 2;
    }
    return s;
}

unsigned long long getCnt(unsigned long long num) {

    unsigned long long cnt = 0;
    string s = getBin(num);
    for (int i=0; i<s.size(); i++) {
        if (i != 0) num -= (1ULL<<(i-1));
        unsigned long long a = num/(1ULL<<(i+1))*(1ULL<<i);
        unsigned long long b = min(1ULL<<i, num%(1ULL<<(i+1)));
        cnt += (a+b);
    }
    return cnt;
}

int main() {

    cin >> A >> B;
    cout<<getCnt(B)-getCnt(A-1);
    return 0;
}