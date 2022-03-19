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

vector<int> arr[4][3][3][3];

string lan, pos, lv, fd, t, score;

map<string, int> m = {
    {"cpp", 1}, {"java", 2}, {"python", 3},
    {"backend", 1}, {"frontend", 2},
    {"junior", 1}, {"senior", 2},
    {"chicken", 1}, {"pizza", 2}
};


void setarr(const vector<string>& info) {
    
    for (auto s : info) {
        stringstream in(s);
        in >> lan >> pos >> lv >> fd >> score;

        //해당 조건으로 나올 수 있는 모든 조합을 찾아 해당 배열에 score 추가
        for (auto l : {0, m[lan]}) {
            for (auto p : {0, m[pos]}) {
                for (auto e : {0, m[lv]}) {
                    for (auto f : {0, m[fd]}) {
                        arr[l][p][e][f].push_back(stoi(score));
                    }
                }
            }
        }
    }
}


void sortarr() {
    
    //조건 별 점수들을 오름차순으로 정렬
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                for (int l=0; l<3; l++)
                    sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());
            }
        }
    }
}


vector<int> solution(vector<string> info, vector<string> query) {
    
    setarr(info);
    sortarr();
    
    vector<int> ret;
    for (auto q : query) {
        stringstream in(q);
        in >> lan >> t >> pos >> t >> lv >> t >> fd >> score;

        //조건별 점수들이 오름차순으로 정렬되어있으므로 score 이상의 값들을 가지는 원소들을 logN에 탐색 가능
        vector<int> v = arr[m[lan]][m[pos]][m[lv]][m[fd]];
        int cnt = v.end()-lower_bound(v.begin(), v.end(), stoi(score));
        ret.push_back(cnt);
    }
    return ret;
}