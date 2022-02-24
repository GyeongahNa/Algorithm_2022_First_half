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
using ii = pair<int, int>;

#define X first;
#define Y second;

int main() {

    int N;
    scanf("%d", &N);

    vector<int> v(N), ans(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    stack<int> st;
    st.push(1000001);

    for (int i=N-1; i>=0; i--) {
        while (!st.empty() && (st.top() <= v[i]))
            st.pop();
        ans[i] = st.top();
        st.push(v[i]);
    }

    for (int i=0; i<N; i++) {
        if (ans[i] == 1000001) printf("%d ", -1);
        else printf("%d ", ans[i]);
    }
    return 0;
}