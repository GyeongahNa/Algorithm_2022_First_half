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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<ii> score;

bool cmp(ii a, ii b) {
    if (a.X > b.X) return true;
    if (a.X < b.X) return false;
    if (a.Y < b.Y) return true;
    return false;
}

int main() {

    cin >> N;
    score.resize(N);
    for (int i=0; i<N; i++)
        cin >> score[i].X >> score[i].Y;

    sort(score.begin(), score.end(), cmp);

    int cnt = 0;
    for (int i=5; i<N; i++) {
        if (score[i].X == score[4].X) cnt++;
    }
    cout<<cnt;
    return 0;
}