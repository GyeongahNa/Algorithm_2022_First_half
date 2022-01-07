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

    int N;
    cin >> N;

    int cnt =0;
    while (N--) {
        
        string s;
        cin >> s;

        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        if (st.empty()) cnt++; 
    }
    cout << cnt << "\n";
    return 0;
}