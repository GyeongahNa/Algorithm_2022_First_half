#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

int N;

int main() {

    cin >> N;
    int tmp = N^(~N+1), cnt = 0;
    for (int i=0; i<32; i++) {
        if (tmp&(1<<i)) cnt++;
    }
    cout<<cnt;
    return 0;
}