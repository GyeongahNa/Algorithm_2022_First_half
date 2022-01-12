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
int arr[10];

void func(int k) {

    if (k == M) {
        for (int i=0; i<M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }

    for (int i=1; i<=N; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main() {

    scanf("%d %d", &N, &M);
    func(0);
    return 0;
}