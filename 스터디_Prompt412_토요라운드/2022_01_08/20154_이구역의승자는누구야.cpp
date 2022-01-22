#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int n[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;

    int sum = 0;
    for (char c: s) {
        sum += n[c-'A'];
        if (sum > 10) sum = sum%10;
    }

    if (sum%2 == 0) printf("You're the winner?");
    else printf("I'm a winner!");
    return 0;
}