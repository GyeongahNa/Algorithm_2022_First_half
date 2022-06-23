#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T;

int main() {

    cin >> T;
    while (T--) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        
        string s;
        cin >> s;

        bool chPalin = false;
        bool chlRemove = false;
        bool chrRemove = false;

        int l = 0;
        int r = s.size()-1;
        while (l <= r && s[l] == s[r]) l++, r--;
        if (r < l) chPalin = true;
        
        int tl = l+1;
        int tr = r;
        while (tl <= tr && s[tl] == s[tr]) tl++, tr--;
        if (tr < tl) chlRemove = true;

        tl = l;
        tr = r-1;
        while (tl <= tr && s[tl] == s[tr]) tl++, tr--;
        if (tr < tl) chrRemove = true;

        if (chPalin) cout<<"0\n";
        else if (chlRemove || chrRemove) cout<<"1\n";
        else cout<<"2\n";
    }

    return 0;
}