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

int N, K;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> K;
    
    int bf = 0;
    for (int i=1; i<=N; i++) {
        string s = to_string(i);
        int af = bf+s.size();
        if (af < K) {
            bf = af;
            continue;
        }
        cout<<s[K-bf-1];
        return 0;
    }
    cout<<-1;
    return 0;
}