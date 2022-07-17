#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N, k, t, M, p, q;
int cls[1005][55];

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> t;
            cls[i][t] = true;
        }
    }

    cin >> M;
    for (int i=0; i<M; i++) {
        vector<bool> v(51, true);
        cin >> p;
        for (int j=0; j<p; j++) {
            cin >> q;
            v[q] = false;
        }

        int cnt = 0;
        for (int j=0; j<N; j++) {
            bool check = true;
            for (int k=1; k<51; k++) {
                if (!cls[j][k] || !v[k]) continue;
                check = false;
                break;
            }
            if (check) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}