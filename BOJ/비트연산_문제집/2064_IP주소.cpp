#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <climits>
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

int N;
vector<unsigned int> v;

void printbinary(unsigned int num) {

    int idx = 0;
    for (int i=3; i>=0; i--) {
        unsigned int tmp = num&(((1LL<<32)-1)>>((3-i)*8));
        tmp &= (((1LL<<32)-1)<<(i*8));
        tmp = tmp>>(i*8);
        cout<<tmp;
        if (i != 0) cout<<".";
    }
    cout<<"\n";
}

int main() {

    cin >> N;
    while (N--) {

        string s;
        cin >> s;
        s += '.';

        int pos = 0;
        unsigned int num = 0;
        for (int i=3; i>=0; i--) {
            int idx = s.find('.', pos);
            string sb = s.substr(pos, idx-pos);
            pos = idx+1;
            num |= ((unsigned int)(stoul(sb)))<<(i*8);
        }
        v.push_back(num);
    }

    int idx;
    for (idx=31; idx>=0; idx--) {
        bool check = true;
        for (int i=1; i<v.size(); i++) {
            if ((v[i-1]&(1<<idx)) == (v[i]&(1<<idx))) continue;
            check = false;
            break;
        }
        if (!check) break;
    }

    unsigned int mask = ((1LL<<32)-1)<<(idx+1);
    unsigned int ad = v[0]&mask;
    printbinary(ad);
    printbinary(mask);
}