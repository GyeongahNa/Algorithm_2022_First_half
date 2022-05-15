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

    int N;
    scanf("%d", &N);

    vector<ii> v(N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &v[i].X, &v[i].Y);
    }

    int cnt = 0;
    for (int i = 0; i<N; i++) {
        bool isok = true;
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            if (v[i].X > v[j].X && v[i].Y >= v[j].Y) isok = false;
            else if (v[i].Y > v[j].Y && v[i].X >= v[j].X) isok = false;
        }
        if (isok == true) cnt++;
    }
    printf("%d", cnt);
    return 0;
}