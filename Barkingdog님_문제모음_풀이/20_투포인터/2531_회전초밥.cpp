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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, d, k, c;
vector<int> v;
vector<int> check(3005, 0);

int twoPointer() {

    int st = 0, en = k, sz = v.size();
    int nkind = 0, mxkind = 0, ncupon = 0;

    for (int i=0; i<k; i++) {
        if (!check[v[i]]) nkind++;
        if (v[i] == c) ncupon++;
        check[v[i]]++;
    }
    mxkind = max(nkind, mxkind);
    if (!ncupon) mxkind++;

    while (st < sz && en < sz) {
       
        if (check[v[st]] == 1) nkind--;
        if (v[st] == c) ncupon--;
        check[v[st++]]--;

        if (!check[v[en]]) nkind++;
        if (v[en] == c) ncupon++;
        check[v[en++]]++;
        mxkind = max(mxkind, nkind+(ncupon ? 0 : 1));
    }

    return mxkind;
}

int main() {

    scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    for (int i=0; i<k; i++) v.push_back(v[i]);
    printf("%d ", twoPointer());
    return 0;
}