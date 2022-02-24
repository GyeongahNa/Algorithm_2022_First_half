#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, M;
int d[10];
int arr[10];

void func(int k) {

    if (k == M) {
        for (int i=0; i<M; i++)
            printf("%d ", d[arr[i]]);
        printf("\n");
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1];
    for (int i=st; i<N; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {
    
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++)
        scanf("%d", &d[i]);
    
    sort(d, d+N);
    func(0);
    return 0;
}