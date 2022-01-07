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

    char s[35];
    scanf("%s", s);
    string str(s);

    stack<int> st;
    bool isok = true;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '(') st.push(-2);
        else if (str[i] == '[') st.push(-3);
        else  {
            int close = 0;
            if (str[i] ==')') close = -2;
            else close = -3;

            int sum = 0;
            while (!st.empty() && st.top() >= 0) {
                sum += st.top();
                st.pop();
            }
            if (st.empty() || st.top() != close) {
                isok = false;
                break;
            }

            st.pop();
            sum = (sum == 0) ? -close : sum*(-close);
            st.push(sum);
        }
    }

    int re = 0;
    while (!st.empty()) {
        if (st.top() < 0) {
            isok = false;
            break;
        }
        re += st.top();
        st.pop();
    }

    if (!isok) printf("0");
    else printf("%d", re);

}