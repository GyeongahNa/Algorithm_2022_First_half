#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, K;
vector<int> v;

bool check(int off, int s, int e) {
    return s <= off && off <= e;
}

void printTime(int t) {
    t = t%(24*60);
    int h = t/60, m = t%60;
    if (h < 10) cout<<"0";
    cout<<h<<":";
    if (m < 10) cout<<"0";
    cout<<m<<"\n";
}

int main() {

    cin >> N >> K;

    int t = 0;
    int s = N*24*60, e = (N+1)*24*60-1;

    for (int i=0; i<=N; i++) {
        int off1 = (24*i+15)*60+t;
        int off2 = (24*i+18)*60+t;
        int off3 = (24*i+21)*60+t;
        if (check(off1, s, e)) v.push_back(off1); 
        if (check(off2, s, e)) v.push_back(off2);
        if (check(off3, s, e)) v.push_back(off3);
        t += K;
    }

    cout<<v.size()<<"\n";
    for (auto t : v) printTime(t);
    return 0;
}