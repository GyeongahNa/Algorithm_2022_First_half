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

int N;
string name[100001];
vector<int> arr[100001];

bool cmp(vector<int> a, vector<int> b) {

    if (a[1] != b[1]) return a[1] > b[1];
    if (a[2] != b[2]) return a[2] < b[2];
    if (a[3] != b[3]) return a[3] > b[3];
    return name[a[0]] < name[b[0]];
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char s[15];
        scanf("%s", s);
        name[i] = string(s);

        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        arr[i] = {i, x, y, z};
    }

    stable_sort(arr, arr+N, cmp);
    for (int i=0; i<N; i++)
        printf("%s\n", name[arr[i][0]].c_str());
    return 0;
}