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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    getline(cin, s);
    while (s != ".") {
        
        stack<char> st;
        bool isyes = true;
        for (char c : s) {
            if (c == '(' || c == '[') st.push(c);
            else if (c == ')' || c == ']') {
                char t = (c == ')') ? '(' : '[';
                if (st.empty() || st.top() != t) {
                    isyes = false;
                    break;
                }
                st.pop();
            }
        }

        if (st.empty() && isyes) cout << "yes\n";
        else cout << "no\n";
        getline(cin, s);
    }
    return 0;
}