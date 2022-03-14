#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
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

int take(vector<vector<int>>& board, const int& c) {
    
    int r = 0;
    int sz = board.size();
    while (r < sz && !board[r][c]) r++;
    
    if (r >= sz) return 0;
    int tmp = board[r][c];
    board[r][c] = 0;
    return tmp;
}

int solution(vector<vector<int>> board, vector<int> moves) {

    int ret = 0;
    stack<int> st;
    for (auto x : moves) {
        int d = take(board, x-1);
        if (!d) continue;
        if (!st.empty() && st.top() == d) {
            ret += 2;
            st.pop();
            continue;
        }
        st.push(d); 
    }
    return ret;
}