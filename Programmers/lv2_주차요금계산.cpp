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
using iii = tuple<int, int, int>;

#define X first
#define Y second

map<string, int> mIn, mTot;

vector<int> solution(vector<int> fees, vector<string> records) {
    
    for (auto s : records) {
        
        //시각, 차량번호, 입출차 파싱
        stringstream in(s);
        string t, n, io;
        in >> t >> n >> io;
        int time = stoi(t.substr(0, 2))*60+stoi(t.substr(3));
        
        //입차일 때 입차 시각 기록
        if (io == "IN") {
            mIn[n] = time;
            continue;
        }

        //출차일 때 출차시각에서 최근의 입차시각을 빼 시간을 계산한 후 더하여 기록
        mTot[n] += time-mIn[n];
        mIn[n] = -1;
    }
    
    vector<int> ret;
    for (auto [key, val] : mIn) {

        //입차시각만 주어지고 출차시각은 주어지지 않은 경우 시간 추가
        if (val != -1) mTot[key] += (23*60+59-val);

        //요금 계산
        int f = fees[1];
        if (mTot[key] > fees[0]) f += (((mTot[key]-fees[0])+fees[2]-1)/fees[2])*fees[3];
        ret.push_back(f);
    }
    return ret;
}