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
ii input[100005];
ii tmp[100005];

void merge(int st, int en) {

    int mid = (st+en)/2;
    int i = st, j = mid;
    for (int k=st; k<en; k++) {
        if (i >= mid) tmp[k] = input[j++];
        else if (j >= en) tmp[k] = input[i++];
        else if (input[i] <= input[j]) tmp[k] = input[i++];
        else tmp[k] = input[j++];
    }

    for (int k=st; k<en; k++) input[k] = tmp[k];
}

void mergeSort(int st, int en) {

    if (en == st+1) return ;
    int mid = (st+en)/2;
    mergeSort(st, mid);
    mergeSort(mid, en);
    merge(st, en);
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d %d", &input[i].Y, &input[i].X);
    
    mergeSort(0, N);
    
    for (int i=0; i<N; i++)
        printf("%d %d\n", input[i].Y, input[i].X);
}   