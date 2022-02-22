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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ss = pair<string, string>;

#define X first
#define Y second

int N;
vector<string> venter, vleave, vleft;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char name[10], state[10];
        scanf("%s %s", name, state);
        if (string(state) == "enter") venter.push_back(string(name));
        else vleave.push_back(string(name));
    }

    sort(venter.begin(), venter.end());
    sort(vleave.begin(), vleave.end());

    for (int i=0; i<venter.size(); i++) {
        if (i > 0 && venter[i-1] == venter[i]) continue;
        int nin = upper_bound(venter.begin(), venter.end(), venter[i])-lower_bound(venter.begin(), venter.end(), venter[i]);
        int nout = upper_bound(vleave.begin(), vleave.end(), venter[i])-lower_bound(vleave.begin(), vleave.end(), venter[i]);
        if (nin > nout) vleft.push_back(venter[i]);
    }

    sort(vleft.begin(), vleft.end(), greater<>());
    for (int i=0; i<vleft.size(); i++) printf("%s\n", vleft[i].c_str());
    return 0;
}

/*이분탐색은 반드시 오름차순으로 정렬되어있을 때만 사용가능하다*/