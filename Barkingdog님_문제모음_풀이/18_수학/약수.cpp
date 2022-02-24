#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int main() {

    int N;
    scanf("%d", &N);

    vector<int> vre;
    for (int i=1; i*i<=N; i++) {
        if (N%i != 0) continue;
        if (i == N/i) {
            vre.push_back(i);
            continue;
        }
        vre.push_back(i);
        vre.push_back(N/i);
    }

    sort(vre.begin(), vre.end());
    for (int i=0; i<vre.size(); i++)
        printf("%d ", vre[i]);
    return 0;
}