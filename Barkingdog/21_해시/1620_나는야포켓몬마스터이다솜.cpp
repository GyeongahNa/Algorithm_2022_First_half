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
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
vector<string> num(100005, "");
unordered_map<string, int> name;

bool check(string s) {

    for (int i=0; i<s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

int main() {

    scanf("%d %d", &N, &M);
    num.push_back("");
    for (int i=1; i<=N; i++) {
        char x[25];
        scanf("%s", x);
        num[i] = x;
        name.insert({x, i}); //name[x] = i;
    }

    for (int i=0; i<M; i++) {
        char x[25];
        scanf("%s", x);
        if (check(string(x))) printf("%s\n", num[stoi(x)].c_str());
        else printf("%d\n", name[string(x)]);
    }
    return 0;
}