#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
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

int N, M;
vector<ii> v(10005);

int main() {

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        int num = 0;
        for (auto c : s) num |= (1<<(c-'a'));
        v[i] = {num, num};
    }

    for (int i=0; i<M; i++) {
        char x;
        int cmd, al;
        cin >> cmd >> x;
        al = x-'a';

        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (cmd == 1 && (v[i].X&(1<<al))) v[i].Y &= ~(1<<al);
            else if (cmd == 2 && (v[i].X&(1<<al))) v[i].Y |= 1<<al;
            if (v[i].X == v[i].Y) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}