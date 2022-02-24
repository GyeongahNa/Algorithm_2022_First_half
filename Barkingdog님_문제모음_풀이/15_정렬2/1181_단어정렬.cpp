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

int N;
string arr[20005];

bool cmp(string a, string b) {

    if (a.size() != b.size()) return a.size() < b.size();
    return strcmp(a.c_str(), b.c_str()) < 0;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char s[55];
        scanf("%s", s);
        arr[i] = string(s);
    }

    stable_sort(arr, arr+N, cmp);
    for (int i=0; i<N; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        printf("%s\n", arr[i].c_str());
    }
    return 0;
}