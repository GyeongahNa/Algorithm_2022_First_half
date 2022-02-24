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
    
    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    stack<int> st;
    vector<int> re;
    string sign = "";
    int n = 1, i = 0;

    while (i < N && re.size() < N) {
        if (n <= v[i]) {
            while (n <= v[i]) {
                st.push(n);
                sign += "+\n";
                n++;
            }
            if (!st.empty()) {
                re.push_back(st.top());
                st.pop();
                sign += "-\n";
            }
        }
        else {
            while (!st.empty() && st.top() != v[i]) {
                re.push_back(st.top());
                st.pop();
                sign += "-\n";
            }
            if (!st.empty()) {
                re.push_back(st.top());
                st.pop();
                sign += "-\n";
            }
        }
        i++;
    }
    
    if (re == v) printf("%s", sign.c_str());
    else printf("NO\n");
    return 0;
}