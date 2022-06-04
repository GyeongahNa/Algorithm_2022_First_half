#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;

int conv(int num) {

    if (num <= 15) return num;
    num -= 16;
    if (num/14%2) return 2+num%14;
    else return 14-num%14;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;
        N = conv(N);

        stack<string> st;
        for (int i=0; i<4; i++) {
            if (N%2) st.push("딸기");
            else st.push("V");
            N/=2;
        }

        while (!st.empty()) {
            cout<<st.top();
            st.pop();
        }
        cout<<"\n";
    }
}