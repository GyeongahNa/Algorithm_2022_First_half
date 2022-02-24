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
int S[25][25];
int arr1[25];
int arr2[25];
int isused[25];
int sum;
int mn = MX;

/* 베코 출제 유형 */

void divide() {

    bool check[25];
    memset(check, false, sizeof(check));

    for (int i=0; i<N/2; i++)
        check[arr1[i]] = 1;
    
    int idx = 0;
    for (int i=0; i<N; i++) {
        if (check[i]) continue;
        arr2[idx] = i;
        idx++;
    }   
}

void func(int k) {

    if (k == N/2) {

        divide();
        int start = 0, link = 0;
        for (int i=0; i<N/2; i++) {
            for (int j=i+1; j<N/2; j++) {
                start += S[arr1[i]][arr1[j]];
                start += S[arr1[j]][arr1[i]];
                link += S[arr2[i]][arr2[j]];
                link += S[arr2[j]][arr2[i]];
            }
        }
        mn = min(mn, abs(start-link));
        return ;
    }

    int st = 0;
    if (k != 0) st = arr1[k-1]+1;
    for (int i=st; i<N; i++) {
        if (isused[i]) continue;
        arr1[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &S[i][j]);
            sum += S[i][j];
        }
    }

    func(0);
    printf("%d", mn);
    return 0;
}