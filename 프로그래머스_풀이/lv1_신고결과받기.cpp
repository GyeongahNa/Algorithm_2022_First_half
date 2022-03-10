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
using iii = tuple<int, int, int>;

#define X first
#define Y second


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    map<string, int> conv;
    
    // {사람이름, 번호} map 초기화
    int sz = id_list.size();
    for (int i=0; i<sz; i++) conv[id_list[i]] = i;
    
    // 신고 목록에서 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    // 신고 목록 벡터화
    vector<ii> v;
    for (const auto& s : report) {
        stringstream in(s);
        string p1, p2;
        in >> p1 >> p2;
        v.push_back({conv[p1], conv[p2]});
    }
    
    //신고된 횟수, 정지된 사람 수 카운트
    vector<int> cnt(sz), re(sz);
    for (auto [p1, p2] : v) cnt[p2]++; 
    for (auto [p1, p2] : v) if (cnt[p2] >= k) re[p1]++; 
    return re;
}

/*
1) unique()를 이용하여 중복 제거 
1) stringstream을 이용하여 문자열 split 처리
*/