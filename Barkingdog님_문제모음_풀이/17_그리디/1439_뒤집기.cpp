#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using ll = pair<long long, long long>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string s;

int main() {

    char str[1000005];
    scanf("%s", str);
    s = string(str);

    int nzero = 0, none = 0;
    
    if (s[0] == '0') nzero++;
    else none++;

    for (int i=1; i<s.size(); i++) {
        if (s[i] == '0' && s[i-1] != s[i]) nzero++;
        else if (s[i] == '1' && s[i-1] != s[i]) none++;
    }

    printf("%d", min(nzero, none));
    return 0;
}