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
using ll = long long;
using llll = pair<ll, ll>;

#define X first
#define Y second

ll N;
vector<llll> vcmd;
vector<ll> vs, vspsum; //vsize
vector<vector<ll>> vc(200005, vector<ll>(0)), vcpsum(200005, vector<ll>(0)); //vcolor

int main() {
    
    cin >> N;
    vcmd.resize(N);
    vs.resize(N);
    
    for (int i=0; i<N; i++) {
        cin >> vcmd[i].X >> vcmd[i].Y;
        vs[i] = vcmd[i].Y;
        vc[vcmd[i].X].push_back(vcmd[i].Y);
    }
    
    //전체 size 정렬 및 누적합 구하기
    sort(vs.begin(), vs.end());
    vspsum.resize(N);
    vspsum[0] = vs[0];
    for (int i=1; i<N; i++) vspsum[i] = vspsum[i-1]+vs[i];
    
    //색깔별 size 정렬 및 누적합 구하기
    for (int i=1; i<200005; i++) {
        if (!vc[i].size()) continue;
        sort(vc[i].begin(), vc[i].end());
        vcpsum[i].resize(vc[i].size());
        vcpsum[i][0] = vc[i][0];
        for (int j=1; j<vcpsum[i].size(); j++)
            vcpsum[i][j] = vcpsum[i][j-1]+vc[i][j];
    }

    
    //입력마다 사로잡을 수 있는 크기의 합 구하기
    for (auto [c, s] : vcmd) {
        int idx1 = lower_bound(vs.begin(), vs.end(), s)-vs.begin(); 
        int idx2 = lower_bound(vc[c].begin(), vc[c].end(), s)-vc[c].begin();
        ll sum = 0; //작은 공들의 합 - 작고 같은 번호 공들의 합
        if (idx1) sum += vspsum[idx1-1]; 
        if (idx1 && idx2) sum -= vcpsum[c][idx2-1];
        cout<<sum<<'\n';
    }
    return 0;
}