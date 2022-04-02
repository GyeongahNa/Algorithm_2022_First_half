#include <cstdio>
#include <cstring>
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

int n;
long long k;
long long P2[70];
string pwd;

int main() {

    cin >> pwd >> k;
    P2[0] = 1;
    for (int i=1; i<=65; i++) P2[i] = P2[i-1]*2;

    for (auto c : pwd) {
        if (c == '1' || c == '2' || c == '6' || c =='7') n++;
    }

    if (P2[n] < k) {
        cout<<-1;
        return 0;
    }

    k--;
    string s = "";
    for (int i=0; i<n; i++) {
        s = char(k%2+'0') + s;
        k /= 2;
    }

    int idx = 0;
    for (auto& c : pwd) {
        if (c == '1' || c == '6') {
            if (!(s[idx++]-'0')) c = '1';
            else c = '6';
        }
        else if (c == '2' || c == '7') {
            if (!(s[idx++]-'0')) c = '2';
            else c = '7';
        }
    }
    cout<<pwd;
    return 0;
}