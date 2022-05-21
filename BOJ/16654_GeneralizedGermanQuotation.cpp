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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

string s, ret;
stack<string> st1;
stack<char> st2;
bool check;

int main() {

    cin >> s;

    for (int i=0; i<s.size(); i+=2) {
        string tok = s.substr(i, 2);
        if (tok.length() == 1 || tok[0] != tok[1]) check = true;
        if (st1.empty() || st1.top() == tok) {
            st1.push(tok);
            ret += '[';
        }
        else {
            st1.pop();
            ret += ']';
        }
    }

    for (auto x : ret) {
        if (x == '[') st2.push(x);
        else if (st2.empty()) check = true;
        else st2.pop();
    }
    if (!st2.empty()) check = true;
    
    if (check) cout<<"Keine Loesung";
    else cout<<ret;
    return 0;
}