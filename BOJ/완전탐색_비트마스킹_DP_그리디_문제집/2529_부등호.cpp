#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string s;

int k;
int arr[10];
bool check[10];

long long mx;
long long mn = __LONG_LONG_MAX__;
long long p10[15];


void Permutation(int n) {

    if (n == k+1) {

        int idx = 0;
        for (auto c : s) {
            if (c == ' ') continue;
            if (c == '<' && arr[idx] >= arr[idx+1]) return ;
            if (c == '>' && arr[idx] <= arr[idx+1]) return ;
            idx++;
        }

        long long num = 0;
        for (int i=0; i<k+1; i++) num += arr[i]*p10[k-i];
        mx = max(mx, num);
        mn = min(mn, num);
        return ;
    }

    for (int i=0; i<10; i++) {
        if (check[i]) continue;
        arr[n] = i;
        check[i] = true;
        Permutation(n+1);
        check[i] = false;
    }
}

void setPow() {

    p10[0] = 1;
    for (int i=1; i<15; i++) p10[i] = p10[i-1]*10;
}

void printNum(long long num) {

    int sz = k+1-to_string(num).size();
    for (int i=0; i<sz; i++) cout<<"0";
    cout<<num<<"\n";
}

int main() {

    cin >> k;
    getline(cin, s);
    getline(cin, s);
    setPow();
    Permutation(0);
    
    printNum(mx);
    printNum(mn);

    return 0;
}