#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;

    string s;
    while (N--) {
        cin >> s;

        list<char> L;
        list<char>::iterator cursor = L.begin();

        for (char c : s) {
            if (c == '<') {
                if (cursor != L.begin()) cursor--;
            }
            else if (c == '>') {
                if (cursor != L.end()) cursor++;
            }
            else if (c == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else L.insert(cursor, c);
        }
        
        for (char c : L) cout << c;
        cout<<endl;
    }
    return 0;
}