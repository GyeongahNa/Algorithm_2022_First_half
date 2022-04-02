#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
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

int L, C;
char A[20];
int arr[20];

bool check(char a) {

    if (a == 'i' || a == 'e' || a == 'a' || a == 'o' || a == 'u') 
        return true;
    return false;  
}

void combination(int k) {

    if (k == L) {
        int cnt = 0;
        for (int i=0; i<L; i++) {
            if (check(A[arr[i]])) cnt++;
        }
        if (cnt >= 1 && L-cnt >= 2) {
            for (int i=0; i<L; i++) cout<<A[arr[i]];
            cout<<"\n";
        }
        return ; 
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<C; i++) {
        arr[k] = i;
        combination(k+1);
    }
}

int main() {

    cin >> L >> C;
    for (int i=0; i<C; i++) cin >> A[i];
    sort(A, A+C);
    combination(0);
    return 0;
}