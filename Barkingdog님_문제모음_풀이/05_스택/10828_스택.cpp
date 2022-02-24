#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    stack<int> st;
    cin >> N;
    
    while (N--) {

        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (cmd == "pop") {
            if (st.empty()) 
                cout << "-1\n";
            else {
                int n = st.top();
                st.pop();
                cout << n << "\n";
            }
        }
        if (cmd == "size") 
            cout << st.size() << "\n";
        else if (cmd == "empty") {
            cout << st.empty() << "\n";
        }
        else if (cmd == "top") {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }
    return 0;
}