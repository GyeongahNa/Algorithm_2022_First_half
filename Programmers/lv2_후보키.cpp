#include <cstdio>
#include <cstring>
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


void getcomb(vector<vector<int>>& vcomb, int sz) {
    
    int N = 1<<sz;
    for (int n=1; n<N; n++) {
        int tmp = n;
        vector<int> vtmp(sz, 0);
        for (int i=0; i<sz; i++) {
            vtmp[sz-1-i] = tmp%2;
            tmp = tmp/2;
        }
        vcomb.push_back(vtmp);
    }
}


bool contain(vector<int> key1, vector<int> key2) {
    
    for (int i=0; i<key1.size(); i++) {
        //key1에서 포함되지 않은 컬럼이 key2에서 포함된 경우 키는 관련이 없음
        if (!key1[i] && key2[i]) return false;
    }
    return true;
}


bool unique(const vector<vector<string>>& relation, const vector<int>& key) {
    
    int sz = key.size();
    vector<vector<string>> v;
    
    for (auto s : relation) {
        vector<string> vtmp;
        for (int i=0; i<sz; i++) {
            if (!key[i]) continue;
            vtmp.push_back(s[i]);
        }

        //중복되는 요소가 있는지 확인
        if (find(v.begin(), v.end(), vtmp) != v.end()) return false;
        v.push_back(vtmp);
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    
    //가능한 모든 키 조합 찾기
    vector<vector<int>> vcomb;
    getcomb(vcomb, relation[0].size());
    
    vector<vector<int>> keys;
    for (int i=0; i<vcomb.size(); i++) {
        
        //특정 키 조합이 최소성을 만족하는지 확인
        //(더 작은 단위의 키 조합이 이미 선택되었는지 확인)
        bool check = true;
        for (int j=0; j<i; j++) {
            if (!contain(vcomb[i], vcomb[j])) continue; 
            if (find(keys.begin(), keys.end(), vcomb[j]) == keys.end()) continue;
            check = false; 
            break;
        }
        
        //특정 키 조합이 최소성과 유일성을 만족하는지 확인
        if (!check || !unique(relation, vcomb[i])) continue;
        keys.push_back(vcomb[i]);
    }
    
    return (int)keys.size();
}