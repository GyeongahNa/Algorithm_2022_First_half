#include <cstdio>
#include <cstring>
#include <climits>
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

int N, cnt;
int arr[20];
string origins;

long long mx = INT_MIN;


long long operate(long long x, char sign, long long y) {

    if (sign == '+') return x+y;
    if (sign == '-') return x-y;
    return x*y;
}


long long calculate(int k) {

    bool check[20];
    memset(check, false, sizeof(check));

    for (int i=0; i<k; i++)
        check[2*arr[i]] = true;

    int i = 0;
    long long re = 0;
    if (check[0]) {
        re = operate(origins[0]-'0', origins[1], origins[2]-'0');
        i += 3;
    }
    else {
        re = origins[0]-'0';
        i += 1;
    }

    while (i < N) {
        if (check[i+1]) {
            long long tmp = operate(origins[i+1]-'0', origins[i+2], origins[i+3]-'0');
            re = operate(re, origins[i], tmp);
            i += 4;
        }
        else {
            re = operate(re, origins[i], origins[i+1]-'0');
            i += 2;
        }
    }

    return re;
}


void func(int k) {

    mx = max(calculate(k), mx);
    if (k == cnt/2) return;

    int st = 0;
    if (k != 0) st = arr[k-1]+2;
    for (int i=st; i<cnt-1; i++) {
        arr[k] = i;
        func(k+1);
    }
}


int main() {

    scanf("%d", &N);
    
    char str[20];
    scanf("%s", str);
    origins = string(str);

    for (int i=0; i<N; i++) {
        if (origins[i] >= '0' && origins[i] <= '9') cnt++;
    }

    func(0);
    printf("%lld", mx);
    return 0;
}   