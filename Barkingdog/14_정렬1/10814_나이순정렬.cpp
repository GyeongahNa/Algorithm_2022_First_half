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
ii info[1000005];
ii tmp[1000005];
string name[100005];

void merge(int st, int en) {

    int mid = (st+en)/2;
    int i = st, j = mid;
    for (int k=st; k<en; k++) {
        if (i >= mid) tmp[k] = info[j++];
        else if (j >= en) tmp[k] = info[i++];
        else if (info[i] <= info[j]) tmp[k] = info[i++];
        else tmp[k] = info[j++];
    }

    for (int k=st; k<en; k++) info[k] = tmp[k];
}

void mergeSort(int st, int en) {

    if (en == st+1) return;
    int mid = (st+en)/2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}

void print() {

    for (int i=0; i<N; i++) {
        printf("%d %s\n", info[i].X, name[info[i].Y].c_str());
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        char y[105];
        scanf("%d %s", &x, y);
        info[i] = {x, i};
        name[i] = string(y);
    }

    mergeSort(0, N);
    print();
    return 0;
}