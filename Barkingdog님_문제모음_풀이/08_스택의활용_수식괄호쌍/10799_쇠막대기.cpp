#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {

    char s[100005];
    scanf("%s", s);
    string str(s);

    stack<char> st;

    int sum = 0;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '(') st.push('(');
        else {
            st.pop();
            if (i > 0 && str[i-1] == '(')
                sum += st.size();
            else sum += 1;        
        }
    }
    printf("%d", sum);
    return 0;
}