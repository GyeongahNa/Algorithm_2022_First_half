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
using is = pair<int, string>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


bool search(string s1, string s2) {
    
    for (auto c : s1) {
        if (s2.find(c) == string::npos) return false;
    }
    return true;
}


void combination(int k, int n, vector<int>& arr, const vector<string>& orders, vector<is>& v) {
    
    if (k == n) {
        
        //n개의 단품으로 이루어진 코스
        string s = "";
        for (int i=0; i<k; i++) s += (arr[i]+'A');
    
        //해당 코스가 주문에서 몇번 등장하는지 카운트
        int cnt = 0;
        for (auto ord : orders) {
            if (search(s, ord)) cnt++;
        }   

        //v에 저장 
        v.push_back({cnt, s});
        return ;
    }
    
    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<26; i++) {
        arr[k] = i;
        combination(k+1, n, arr, orders, v);
    }
}


vector<string> solution(vector<string> orders, vector<int> course) {

    vector<string> ans;
    
    for (auto n : course) {
        
        vector<is> v;
        vector<int> arr(15, 0);

        //n개의 단품으로 이루어진 코스 조합을 찾아 해당 코스가 몇개의 주문에서 등장하는지 v에 저장
        combination(0, n, arr, orders, v);
        
        //가장 많은 주문을 받은 코스 파악
        int mx = 0;
        for (auto [t, s] : v) mx = max(t, mx);
        if (mx < 2) continue;
        
        //가장 많은 주문(2번 이상)을 받은 코스들을 ans에 추가
        for (auto [t, s] : v) if (t == mx) ans.push_back(s);
    }

    //정렬
    sort(ans.begin(), ans.end());
    return ans;
}