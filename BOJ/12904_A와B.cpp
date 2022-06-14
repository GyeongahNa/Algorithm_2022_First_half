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

string s, t;
int check;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s >> t;
    
    while (t.size()) {
        
        if (t == s) check = 1;
        if (t.back() == 'A') t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    
    cout<<check;
    return 0;
}