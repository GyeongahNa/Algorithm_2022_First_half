#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int N;
int A[110];

vector<int> op;
int arr[110];
int isused[110];

int mx = -1000000000;
int mn = 1000000000;

void func(int k) {

    if (k == N-1) {

        int re = A[0]; 
        for (int i=0; i<N-1; i++) {
            if (arr[i] == 0) re += A[i+1];
            else if (arr[i] == 1) re -= A[i+1];
            else if (arr[i] == 2) re *= A[i+1];
            else {
                if (re < 0) re = -((-re)/A[i+1]);
                else re /= A[i+1];
            }
        }
        mx = max(mx, re);
        mn = min(mn, re);
    }

    for (int i=0; i<op.size(); i++) {
        if (isused[i]) continue;
        arr[k] = op[i];
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &A[i]);
    for (int i=0; i<4; i++) {
        int x;
        scanf("%d", &x);
        for (int j=0; j<x; j++)
            op.push_back(i); //0:+, 1:-, 2:x, 3:/
    }

    func(0);
    printf("%d\n%d\n", mx, mn);
    return 0;
}