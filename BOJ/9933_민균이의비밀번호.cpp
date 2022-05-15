#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
vector<string> v;

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<N; i++) {
        string s = v[i];
        int sz = s.size();
        if (!(sz%2)) continue;

        string rev = "";
        for (int i=sz-1; i>=0; i--) rev.push_back(s[i]);
        if (!binary_search(v.begin(), v.end(), rev)) continue;
        
        cout<<sz<<" ";
        cout<<s[sz/2];
        break;
    }
    return 0;
}