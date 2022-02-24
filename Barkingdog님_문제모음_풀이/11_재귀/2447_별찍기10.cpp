#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int N;

string blank(int n) {

    string re = "";
    while (n--) re += " ";
    return re;
}

string func(int n) {

    if (n == 1) {
        return "*\n";
    }

    string s = func(n/3), line = "", fs = "", ss = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '\n') {
            fs += (line + line + line + '\n');
            ss += (line + blank(n/3) + line + '\n'); 
            line = "";
        }
        else line += s[i];
    }
    return fs + ss + fs;
}

int main() {

    scanf("%d", &N);
    printf("%s", func(N).c_str());
    return 0;
}