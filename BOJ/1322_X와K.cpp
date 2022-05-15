#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
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

long long x, k;
string sx, sk, sy;

int main() {

    cin >> x >> k;
    while (x) {
        sx = char(x%2+'0') + sx;
        x /= 2;
    }
    while (k) {
        sk = char(k%2+'0') + sk;
        k /= 2;
    }

    long long kidx = sk.size()-1;
    for (long long i=sx.size()-1; i>=0; i--) {
        if (sx[i] == '1') sy = '0' + sy;
        else sy = sk[kidx--] + sy;
        if (kidx < 0) break;
    }

    if (kidx >= 0) {
        for (long long i=kidx; i>=0; i--) sy = sk[i] + sy;
    }

    long long ret = 0;
    for (long long i=0; i<sy.size(); i++)
        if (sy[sy.size()-1-i]-'0') ret |= (1LL<<i);

    cout<<ret;
    return 0;
}