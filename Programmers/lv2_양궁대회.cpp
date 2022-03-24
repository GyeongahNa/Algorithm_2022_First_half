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

int mx;
vector<int> tmp(15, 0);
vector<int> ret = {-1};


bool cmp(vector<int>& v1, vector<int>& v2) {
    
    for (int i=10; i>=0; i--) {
        if (v1[i] > v2[i]) return true;
        else return false;
    }
}

void combination(int k, int n, const vector<int>& info) {
    
    if (k == n) {
        
        //n개를 모두 골랐을 때 각 점수의 개수를 카운트하여 라이언 배열 생성
        vector<int> cnt(11, 0);
        for (int i=0; i<n; i++) cnt[10-tmp[i]]++;
        
        //라이언과 어피치의 점수 합산
        int L = 0, A = 0;
        for (int i=0; i<10; i++) {
            if (!cnt[i] && !info[i]) continue;
            if (cnt[i] > info[i]) L += (10-i);
            else A += (10-i);
        }
        
        //라이언이 진 경우
        if (L <= A) return; 

        //라이언이 이긴경우
        if (L-A < mx) return; //점수차가 최댓값보다 작은 경우
        if (L-A > mx) {ret = cnt; mx = L-A; return; } //점수차가 최댓값보다 큰 경우
        if (cmp(cnt, ret)) ret = cnt; //점수차가 최댓값과 같은 경우(배열 비교)
        return ;
    }
    
    int st = 0;
    if (k != 0) st = tmp[k-1];
    for (int i=st; i<=10; i++) {
        tmp[k] = i;
        combination(k+1, n, info);
    }
}

vector<int> solution(int n, vector<int> info) {
    
    //0부터 10까지의 과녁 중 n개 선택(중복 조합)
    combination(0, n, info);
    return ret;
}