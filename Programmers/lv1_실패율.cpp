#include <cstdio>
#include <cstring>
#include <cmath>
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
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using di = pair<double, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

bool cmp(di a, di b) {
    
    // 실패율이 높은 순으로, 단계는 낮은 순으로 정렬
    if (a.X != b.X) return a.X > b.X;
    return a.Y < b.Y;
}

vector<int> solution(int N, vector<int> stages) {
    
    vector<di> v;
    sort(stages.begin(), stages.end());
    
    //단계별 실패율 구하기
    for (int i=1; i<=N; i++) {
       
        auto up = upper_bound(stages.begin(), stages.end(), i);
        auto lo = lower_bound(stages.begin(), stages.end(), i);
        
        //해당 단계에 진입한 사용자들의 수
        double tot = stages.end()-lo;

        //해당 단계에 진입했으나 아직 통과하지 못한 사용자들의 수
        double nfail = up-lo;
        
        //{살패율, 단계} 저장
        if (tot == 0) v.push_back({0, i});
        else v.push_back({nfail/tot, i});
    }

    //단계별 실패율을 내림차순으로 정렬
    sort(v.begin(), v.end(), cmp);
    
    vector<int> ret;
    for (auto [p, x] : v) ret.push_back(x);
    return ret;
}