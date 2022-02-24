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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using is = pair<int, string>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
unordered_map<string, string> m;

int main() {

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        char ad[25], pwd[25];
        scanf("%s %s", ad, pwd);
        m[ad] = pwd; 
    }

    for (int i=0; i<M; i++) {
        char ad[25];
        scanf("%s", ad);
        printf("%s\n", m[ad].c_str());
    }
    return 0;
}