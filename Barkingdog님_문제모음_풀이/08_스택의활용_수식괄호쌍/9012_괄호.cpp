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

    int N;
    scanf("%d", &N);

    while (N--) {

        char s[100];
        scanf("%s", s);
        string str(s);

        stack<char> st;
        bool isyes = true;
        for (char c : str) {
            if (c == '(') st.push(c);
            else if (!st.empty()) st.pop();
            else {
                isyes = false;
                break;
            }
        }

        if (st.empty() && isyes) cout<<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}