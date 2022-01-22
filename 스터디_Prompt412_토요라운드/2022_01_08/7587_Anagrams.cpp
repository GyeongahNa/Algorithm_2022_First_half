#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

#define X first
#define Y second

int main() {

    while (true) {
        int n;
        scanf("%d", &n);
        if (!n) break;

        vector<string> v;
        vector<vector<int>> cnt(n, vector<int>(26));
        for (int i=0; i<n; i++) {
            char s[10];
            scanf("%s", s);
            string str(s);
            v.push_back(s);
            for (char c : str)
                cnt[i][c-'a']++;
        }

        int midx = 0, mval = -1;
        for (int i=0; i<n; i++) {
            int num = 0;
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                if (cnt[i] == cnt[j]) num++;
            }
            if (num > mval) {
                midx = i;
                mval = num;
            }
        }

        printf("%s ", v[midx].c_str());
        printf("%d\n", mval);
    }
    return 0;
}