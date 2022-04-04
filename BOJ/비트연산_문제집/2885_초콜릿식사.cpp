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

int K;
int mx, mn;

int main() {

    cin >> K;
    string s = "";
    while (K) {
        s = char(K%2+'0')+s;
        K /= 2;
    }

    mx = s.size()-1;
    for (int i=0; i<s.size(); i++) {
        if (s[s.size()-1-i] == '1') {
            mn = i;
            break;
        }
    }

    if (mx == mn) {
        cout<<(1<<mx)<<" "<<0;
        return 0;
    }
    cout<<(1<<(mx+1))<<" "<<(mx+1)-mn;
    return 0;
}