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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K, mx;
int arr[30];
int check[30];
vector<string> v;

int cnt() {

    int re = 0;
    for (const auto& s : v) {
        bool ch = true;
        for (const auto& c : s) {
            if (check[c-'a']) continue;
            ch = false;
            break;
        }
        if (ch) re++;
    }
    return re;
}

void backTracking(int idx) {

    if (idx == K-5) {
        mx = max(mx, cnt());      
        return ;
    }

    int st = 0;
    if (idx != 0) st = arr[idx-1]+1;
    for (int i=st; i<26; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[idx] = i;
        backTracking(idx+1);
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    if (K < 5) {
        cout<<"0";
        return 0;
    }

    vector<char> tmp = {'a', 'n', 't', 'i', 'c'};
    for (const auto& c : tmp) check[c-'a'] = true;

    backTracking(0);
    cout<<mx;
    return 0;
}