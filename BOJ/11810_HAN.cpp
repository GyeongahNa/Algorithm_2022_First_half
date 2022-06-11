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
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

char x;
int Q, n;
string cmd;
int cnt[26];

int dir = 1, cur = 0, idx = 25;

void moveForward(int t) {

    for (int i=0; i<26; i++) cnt[i] += t/26;
    for (int i=1; i<=t%26; i++) cnt[(idx+i)%26]++;
    idx = (idx+t%26)%26;
    cur += t;
}

void moveBackward(int t) {

    for (int i=0; i<26; i++) cnt[i] += t/26;
    for (int i=1; i<=t%26; i++) {
        idx--;
        if (idx < 0) idx += 26;
        cnt[idx]++;
    }
    cur += t;
}

void move(int dir, int t) {

    if (dir == 1) moveForward(t);
    else moveBackward(t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> Q;
    while (Q--) { 
        cin >> cmd;
        if (cmd == "SMJER") {
            cin >> n;
            move(dir, n-cur);
            dir *= -1;
        }
        else {
            cin >> n >> x;
            move(dir, n-cur);
            cout<<cnt[x-'a']<<"\n";
        }
    }
    return 0;
}