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
using iii = tuple<int, int, int>;

#define X first
#define Y second

int main() {

    char s[1005];
    scanf("%s", s);
    string str(s);

    vector<string> v;
    for (int i=0; i<str.size(); i++)
        v.push_back(str.substr(i, str.size()));
    
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
        printf("%s\n", v[i].c_str());
    return 0;
}