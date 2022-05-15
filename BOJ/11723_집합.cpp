#include <cstdio>
#include <cstring>
#include <cmath>
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

int M, num, x;
string cmd;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            num |= (1<<x);
        }
        else if (cmd == "remove") {
            cin >> x;
            num &= ~(1<<x);
        }
        else if (cmd == "check") {
            cin >> x;
            cout<<(((num&(1<<x)) > 0) ? 1 : 0)<<"\n";
        }
        else if (cmd == "toggle") {
            cin >> x;
            num ^= (1<<x);

        }
        else if (cmd == "all") num = (1<<21)-2;
        else num = 0;
    }
}