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
using iis = tuple<int, int, string>;


string solution(string m, vector<string> musicinfos) {

    vector<iis> ret;
    for (int i=0; i<musicinfos.size(); i++) {
        string s =musicinfos[i];

        //s를 파싱하여 {시작 시간, 끝 시간, 제목, 악보}로 저장
        vector<string> v;
        int st = 0, en = 0;
        for (int j=0; j<4; j++) {
            en = s.find(",", st);
            v.push_back(s.substr(st, en-st));
            st = en+1;
        }

        //두 시각의 차이를 구해 총 시간 계산
        int t1 = stoi(v[0].substr(0, 2))*60+stoi(v[0].substr(3));
        int t2 = stoi(v[1].substr(0, 2))*60+stoi(v[1].substr(3));
        int time = t2-t1;

        //총 시간 동안 play된 전체 음악 구하기
        int cnt = 0, idx = 0;
        string play = "";
        while (cnt < time) {
            play += v[3][idx];
            if (idx+1 < v[3].size() && v[3][idx+1] == '#') play += v[3][++idx];
            cnt++; idx++;
            if (idx >= v[3].size()) idx = 0;
        }

        //재생된 전체 음악에 m과 일치하는 부분이 있는지 확인 후 결과 벡터에 {총 시간, -순서, 제목}으로 추가
        int sz = play.size(), msz = m.size();
        for (int j=0; j<sz; j++) {
            if (play.substr(j, msz) != m) continue;
            if (j+msz < sz && play[j+msz] == '#') continue;
            ret.push_back({time, -j, v[2]});
            break;
        }
    }

    if (!ret.size()) return "(None)";

    //정렬 후 가장 앞에 있는 원소의 제목 리턴
    sort(ret.begin(), ret.end(), greater<>());
    return get<2>(ret[0]);
}