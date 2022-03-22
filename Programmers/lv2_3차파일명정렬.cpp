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
#include <cctype>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using sii = tuple<string, int, int>;

#define X first
#define Y second


vector<string> solution(vector<string> files) {
    
    vector<sii> v;
    for (int i=0; i<files.size(); i++) {
        
        string f = files[i];
        string head = "", num = "";
        
        int j, k, sz = f.size();
        for (j = 0; j < sz && !isdigit(f[j]); j++) head += f[j]; //파일명에서 head 파싱
        for (k = j; k < sz && k < j+5 && isdigit(f[k]); k++) num += f[k]; //파일명에서 number 파싱
        for (auto& c : head) if (islower(c)) c=c-32; //head를 모두 대문자로 변환
        v.push_back({head, (num == "" ? 0 : stoi(num)), i}); //{head, number, 인덱스} 저장
    }
    sort(v.begin(), v.end()); 
    
    vector<string> ret; //정렬 후 파일명만 리턴
    for (auto [head, num, i] : v) ret.push_back(files[i]);
    return ret;
}