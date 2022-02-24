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
#include <unordered_set>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
unordered_set<string> s;
vector<string> v;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char name[10], state[10];
        scanf("%s %s", name, state);
        if (string(state) == "enter") s.insert(string(name));
        else s.erase(string(name));
    }

    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<>());
    for (int i=0; i<v.size(); i++) printf("%s\n", v[i].c_str());
    return 0;
}