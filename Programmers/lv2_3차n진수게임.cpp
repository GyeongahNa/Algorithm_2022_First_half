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
using iii = tuple<int, int>;

#define X first
#define Y second


char conv[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    
    string s = "00";
    for (int i=1; i<=100000; i++) {
        
        //수 i를 n진수로 변환하여 각 자리를 stmp에 저장
        int tmp = i;
        string stmp = "";
        while (tmp) {
            stmp += conv[tmp%n];
            tmp /= n;
        }
        reverse(stmp.begin(), stmp.end());
        s += stmp; //stmp 뒤집어 s에 결합
    }
    
    string ret = ""; 
    //튜브의 순서 때 말해야 하는 수만 ret에 차례로 저장
    //튜브가 말해야 하는 인덱스는 p, p+m, p+2m, ..., p+m*(t-1)
    for (int i=p; i<=p+m*(t-1); i+=m) ret += s[i];
    return ret;
}