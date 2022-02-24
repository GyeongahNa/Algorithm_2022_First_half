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
using ll = pair<long long, long long>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;
vector<int> vpos, vneg, vzero;
int re;

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if (x < 0) vneg.push_back(x);
        else if (x > 0) vpos.push_back(x);
        else vzero.push_back(x);
    }
    sort(vpos.begin(), vpos.end(), greater<>());
    sort(vneg.begin(), vneg.end());

    // 양수 처리
    for (int i=0; i<vpos.size()/2; i++)
        re += max(vpos[2*i]*vpos[2*i+1], vpos[2*i]+vpos[2*i+1]);
    if (vpos.size()%2) re += vpos[vpos.size()-1];

    //음수 처리
    for (int i=0; i<vneg.size()/2; i++)
        re += vneg[2*i]*vneg[2*i+1];
    if (vneg.size()%2 && !vzero.size()) re += vneg[vneg.size()-1];

    printf("%d", re);
    return 0;
}