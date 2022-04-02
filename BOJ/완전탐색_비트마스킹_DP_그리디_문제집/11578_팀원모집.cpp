#include <cstdio>
#include <cstring>
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

int N, M;
int mn = INT_MAX;
vector<int> arr(15, 0);
vector<vector<int>> prob(15, vector<int>(0));


void permutationWithRep(int k) {

    if (k == M+1) {

        int cnt = 0;
        vector<bool> check(105, false);
        for (int i=1; i<=M; i++) {
            if (!arr[i]) continue;
            for (auto p : prob[i]) check[p] = true;
            cnt++;
        }

        for (int i=1; i<=N; i++) {
            if (!check[i]) return;
        }

        mn = min(mn, cnt);
        return ;
    }

    for (int i=0; i<=1; i++){
        arr[k] = i;
        permutationWithRep(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int n; cin >> n;
        while (n--) {
            int p; cin >> p;
            prob[i].push_back(p);
        }
    }

    permutationWithRep(1);

    if (mn == INT_MAX) cout<<"-1";
    else cout<<mn;
    return 0;
}