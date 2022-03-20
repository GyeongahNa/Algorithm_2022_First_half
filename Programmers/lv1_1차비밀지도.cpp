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

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> ret;
    for (int i=0; i<n; i++) {
        //i번째 줄 정보 분해
        string s = "";
        int t1 = arr1[i], t2 = arr2[i];
        for (int j=0; j<n; j++) {
            //첫번째 지도와 두번째 지도 중 하나라도 1이면 '#', 아니면 ' ' 연결
            s = ((t1%2)|(t2%2))? '#'+s : ' '+s;
            t1 /= 2; t2 /= 2;
        }
        ret.push_back(s);
    }
    return ret;
}