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

int freq[10];

int main() {

    string s;
    cin >> s;

    for (char c: s)
        freq[c-'0']++;
    
    freq[6] = (freq[6]+freq[9]+1)/2;
    freq[9] = 0;

    int re = 0;
    for (int e : freq)
        re = max(re, e);

    printf("%d", re);
    return 0;
}