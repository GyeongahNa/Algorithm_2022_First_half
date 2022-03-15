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

int ret;
vector<string> vdata;
vector<int> arr(10, 0);
vector<bool> check(10, false);

//카카오 친구들 번호 지정
map<char, int> m = {{'A', 0}, {'C', 1}, {'F', 2}, {'J', 3}, {'M', 4}, {'N', 5}, {'R', 6}, {'T', 7}};


//두 친구 사이에 있는 다른 친구들의 수가 주어진 조건을 만족하는지 확인
bool valid(int num, char sign, int re) {
    if (sign == '=') return num == re;
    if (sign == '>') return num > re;
    return num < re;
}

void permutation(int k) {
    
    if (k == 8) {
        
        //설정된 자리에 대하여 주어진 모든 조건을 만족하는지 확인
        for (auto s : vdata)
            if(!valid(abs(arr[m[s[0]]]-arr[m[s[2]]])-1, s[3], s[4]-'0')) return;
        
        //모든 조건을 만족하는 경우 결과값 1 증가
        ret++;
        return ;
    }
    
    for (int i=1; i<=8; i++) {
        if (check[i]) continue;
        arr[k] = i;
        check[i] = true;
        permutation(k+1);
        check[i] = false;
    }
}

int solution(int n, vector<string> data) {
    
    ret = 0;
    vdata = data;

    //순열(순서고려, 중복 X)을 이용하여 카카오 침구들의 모든 자리 탐색
    permutation(0);
    return ret;
}