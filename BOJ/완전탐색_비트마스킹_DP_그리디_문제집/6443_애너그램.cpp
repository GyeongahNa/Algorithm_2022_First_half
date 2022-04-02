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
#include <climits>
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

int N, sz;
string str;
vector<int> cnt(25, 0);
vector<int> arr(25, 0);


void backTracking(int k) {

    if (k == sz) {
        for (int i=0; i<k; i++) cout<<char(arr[i]+'a');
        cout<<"\n";
        return ;
    }

    for (int i=0; i<26; i++) {
        if (cnt[i] == 0) continue;
        arr[k] = i;
        cnt[i]--;
        backTracking(k+1);
        cnt[i]++;
    }
}

int main() {

    cin >> N;
    while (N--) {
        cin >> str;
        sz = str.size();
        cnt = vector<int>(25, 0);
        arr = vector<int>(25, 0);
        for (auto c : str) cnt[c-'a']++;
        backTracking(0);
    }
    return 0;
}