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

#define X first
#define Y second

int main() {
    
    int N;
    scanf("%d", &N);

    vector<int> v(N);
    for (int i=0; i<N; i++)
        scanf("%d", &v[i]);

    stack<ii> st;
    st.push({1000000001, N});

    long long sum = 0;
    for (int i=N-1; i>=0; i--) {
        while (st.top().X < v[i]) st.pop();
        sum += st.top().Y-i-1; 
        st.push({v[i], i});
    }
    printf("%lld", sum);
    return 0;
}