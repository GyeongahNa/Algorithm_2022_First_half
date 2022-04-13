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

#define X first
#define Y second

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int K, n, d, ret;
vector<vector<char>> gear(5, vector<char>(10));


void getList(vector<ii>& v, int n, int d) {

    v.push_back({n, d});

    int idx = n+1, dir = d;
    while (idx < 5 && gear[idx-1][2] != gear[idx][6]) {
        dir *= -1;
        v.push_back({idx++, dir});
    }

    idx = n-1, dir = d;
    while (idx > 0 && gear[idx][2] != gear[idx+1][6]) {
        dir *= -1;
        v.push_back({idx--, dir});
    }
}


void rotate(int x, int y) {
    
    if (y == 1) {
        for (int i=8; i>=1; i--) gear[x][i] = gear[x][i-1];
        gear[x][0] = gear[x][8];
        return ;
    }

    int tmp = gear[x][0];
    for (int i=0; i<7; i++) gear[x][i] = gear[x][i+1];
    gear[x][7] = tmp;
}


int main() {

    for (int i=1; i<5; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.size(); j++) 
            gear[i][j] = s[j];
    }

    cin >> K;
    while (K--) {
        cin >> n >> d;
        vector<ii> v;
        getList(v, n, d);
        for (auto [x, y] : v) rotate(x, y);
    }

    for (int i=1; i<5; i++) {
        if (gear[i][0]-'0') ret += (1<<(i-1));
    }
    cout<<ret;
    return 0;
}

/* 회전시켜야 하는 톱니바퀴를 구할 때, 출발 톱니바퀴로 부터 왼쪽과 오른쪽으로 전파한다고 생각하면 쉬움*/