#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int N;
string num[55];

bool cmp(string a, string b) {
    
    if (a.length() != b.length()) 
        return a.length() < b.length();
    
    int asum = 0, bsum = 0;
    for (int i=0; i<a.length(); i++) {
        if (a[i] >= '0' && a[i] <= '9') asum += (a[i]-'0');
        if (b[i] >= '0' && b[i] <= '9') bsum += (b[i]-'0');
    }
    
    if (asum != bsum) return asum < bsum;
    return strcmp(a.c_str(), b.c_str()) < 0;
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        char tmp[55];
        scanf("%s", tmp);
        num[i] = string(tmp);
    }

    sort(num, num+N, cmp);
    for (int i=0; i<N; i++)
        printf("%s\n", num[i].c_str());
    return 0;
}