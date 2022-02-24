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
    
    stack<int> st;
    while (N--) {

        int x;
        scanf("%d", &x);
        
        if (x == 0) st.pop();
        else st.push(x);
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    printf("%d", sum);
    return 0;
}