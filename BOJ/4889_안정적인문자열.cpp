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
#include <climits>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

char sign[2] = {'{', '}'};

int main() {

    string s;

    int idx = 1;
    while (1) {

        cin >> s;
        for (auto x : s) if (x == '-') return 0;

        stack<char> st;

        for (auto x : s) {
            if (x == '}' && !st.empty() && st.top() == '{') st.pop();
            else st.push(x);
        }

        int turn = 1, cnt = 0;
        while (!st.empty()) {
            char cur = st.top();
            st.pop();
            if (cur != sign[turn]) cnt++;
            turn = abs(turn-1);
        }
        cout<<idx++<<". "<<cnt<<"\n";
    }
}