#include <cstring>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
int arr[100000];
int isused[100000];

string toBinary(int n) {

    string re = "";
    while (n) {
        re = to_string(n%2)+re;
        n /= 2;
    }
    return re;
}

int check(string s) {

    for (int i=1; i<s.size(); i++) {
        if (s[i] == '1') return 0;
    }
    return 1;
}

int getPow(int n, int k) {

    int re = 1;
    for (int i=0; i<k; i++)
        re *= n;
    return re;
}

int main() {

    scanf("%d", &N);
    for (int i=N; i>=1; i--) {
        if (arr[i]) continue;
        
        string b = toBinary(i);
        int num = getPow(2, b.size()-1);
        for (int j=1; j<=10000; j++) {
            num *= 2;
            if (num-i >= 1 && num-i <= N && !isused[num-i]) {
                arr[i] = num-i;
                arr[num-i] = i;
                isused[num-i] = 1;
                break;
            }
        }
    }

    for (int i=1; i<=N; i++)
        printf("%d\n", arr[i]);
    return 0;
}