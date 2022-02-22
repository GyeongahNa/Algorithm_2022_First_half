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

int K, L;
unordered_map<string, int> m;
vector<is> v;

int main() {

    scanf("%d %d", &K, &L);
    for (int i=0; i<L; i++) {
        char x[10];
        scanf("%s", x);
        m[string(x)] = i;
    }

    for (unordered_map<string, int>::iterator it=m.begin(); it != m.end(); it++)
        v.push_back({it->second, it->first});
    sort(v.begin(), v.end());

    for (int i=0; i<K && i<v.size(); i++) printf("%s\n", v[i].second.c_str());
    return 0;
}