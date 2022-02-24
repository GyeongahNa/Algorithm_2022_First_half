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
#define mod 1000000

//dp[i]: 암호의 i번째 자리까지 해독할 수 있는 경우의 수

string s;
int dp[5005];
int code[5005];

bool one(int i) {
    return code[i] >= 1 && code[i] <= 9;
}

bool two(int i) {
    int twodigit = code[i-1]*10+code[i];
    return twodigit >= 10 && twodigit <= 26;
}

int main() {

    char str[5005];
    scanf("%s", str);
    s = string(str);
    
    int sz = s.size();
    if (sz > 5000) exit(-1);
    if (s[0] < '1' || s[0] > '9') {
        printf("0");
        return 0;
    }

    for (int i=0; i<sz; i++) code[i] = s[i]-'0';

    dp[0] = 1;
    for (int i=1; i<sz; i++) {
        if (i == 1) {
            if (one(i)) dp[i] = 1;
            if (two(i)) dp[i] += 1;
            continue;
        }
        if (one(i)) dp[i] = dp[i-1];
        if (two(i)) dp[i] = (dp[i]+dp[i-2])%mod;
    }

    printf("%d", dp[sz-1]);
    return 0;
}