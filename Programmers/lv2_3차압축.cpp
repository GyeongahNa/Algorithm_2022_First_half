#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second


vector<int> solution(string msg) {
    
    //길이가 1인 모든 단어를 포함하도록 사전 초기화
    vector<string> w(27);
    w[0] = "";
    for (int i=1; i<=26; i++) w[i] = string(1, 'A'+(i-1));

    vector<int> ret;
    while (msg.size()) {
        
        int idx = 0;
        int sz = msg.size(), wsz = w.size();

        //현재 입력과 일치하는 가장 긴 문자열을 찾아 사전의 색인번호를 idx에 저장
        for (int i=sz; i>=1; i--) {
            string s = msg.substr(0, i);
            for (int j=1; j<wsz; j++) {
                if (w[j] != s) continue;
                idx = j;
                break;
            }
            if (idx != 0) break;
        }
        
        ret.push_back(idx);

        //w+c 단어를 사전에 등록
        if (w[idx].size() < msg.size()) w.push_back(w[idx]+msg[w[idx].size()]);

        //입력에서 w 제거
        msg.erase(msg.begin(), msg.begin()+w[idx++].size());
    }
    
    return ret;
}