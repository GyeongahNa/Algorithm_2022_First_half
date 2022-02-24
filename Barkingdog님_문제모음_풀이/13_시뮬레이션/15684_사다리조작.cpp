#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second
#define MX 2147483640

int N, M, H;
int radder[35][15];
int arr[3];
int re = MX;

bool check() {

    for (int i=1; i<=N; i++) {
        int line = i;
        for (int j=1; j<=H; j++) {
            if (line > 1 && radder[j][line-1]) line -= 1;
            else if (line < N && radder[j][line]) line += 1;
        }
        if (i != line) return false;
    }
    return true;
}

void func(int k) {

    if (check()) {
        re = min(re, k);
        return ;
    }
    if (k == 3) return;

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<H*(N-1); i++) {
        int h = i/(N-1)+1;
        int l = i%(N-1)+1;
        if (radder[h][l]) continue;
        if (l > 1 && radder[h][l-1]) continue;
        if (l < N && radder[h][l+1]) continue;
        arr[k] = i;
        radder[h][l] = 1;
        func(k+1);
        radder[h][l] = 0;
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &H);
    for (int i=0; i<M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        radder[a][b] = 1;
    }

    func(0);
    if (re == MX) printf("-1");
    else printf("%d", re);
    return 0;
}

/*0개, 1개, 2개, 3개의 가로줄을 칠하는 경우의 수를 백트래킹으로 모두 구한 후에 사다리타기를 하면 시간초과*/
/*3개의 가로줄을 선택하는 와중에 사다리타기를 하여 조건을 만족하는지 확인*/