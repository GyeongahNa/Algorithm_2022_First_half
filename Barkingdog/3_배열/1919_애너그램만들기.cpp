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

int freq1[26], freq2[26];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    for (char c : s1) freq1[c-'a']++;
    for (char c : s2) freq2[c-'a']++;

    int cnt = 0;
    for (int i=0; i<26; i++)
        cnt += abs(freq1[i]-freq2[i]);
    
    printf("%d", cnt);
    return 0;
}