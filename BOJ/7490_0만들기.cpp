#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int T, N;
int P3[15];
vector<string> v;

string getop(int x) {
    if (x == 0) return " ";
    if (x == 1) return "+";
    return "-";
}

bool isnum(char x) {
    return '1' <= x && x <= '9';
}

int op(int x, int y, char sign) {
    if (sign == '+') return x+y;
    return x-y;
}

bool calc(string exp) {

    int i = 0;
    string tmp = "";
    while (i < exp.size() && (isnum(exp[i]) || exp[i] == ' ')) {
        if (exp[i] != ' ') tmp += exp[i];
        i++;
    }

    int ret = stoi(tmp);
    while (i < exp.size()) {
        tmp = "";
        char sign = exp[i++];
        while (i < exp.size() && (isnum(exp[i]) || exp[i] == ' ')) {
           if (exp[i] != ' ') tmp += exp[i];
           i++;
        }
        ret = op(ret, stoi(tmp), sign);
    }
    if (!ret) return true;
    return false;
}

void printexp(string exp) {

    for (int i=0; i<exp.size(); i++) {
        if (i != 0 && isnum(exp[i-1]) && isnum(exp[i])) cout<<' ';
        cout<<exp[i];
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    P3[0] = 1;
    for (int i=1; i<10; i++) P3[i] = P3[i-1]*3;
    
    cin >> T;
    while (T--) {
        cin >> N;
        vector<string> v;
        for (int num=0; num<P3[N-1]; num++) {
            string exp = "";
            int tmp = num;
            for (int i=1; i<=N; i++) {
                exp += (to_string(i)+getop(tmp%3));
                tmp /= 3;
            }
            if (calc(exp)) v.push_back(exp);
        }
        sort(v.begin(), v.end());
        for (auto& exp : v) cout<<exp<<'\n';
        cout<<'\n';
    }
    return 0;
}