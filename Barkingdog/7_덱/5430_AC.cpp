#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        
        string s;
        int N;
        char c;
        deque<int> d;

        cin >> s;
        cin >> N;
        cin >> c;
        if (N == 0) cin >> c;
        else {
            for (int i=0; i<N; i++) {
                int x;
                cin >> x;
                d.push_back(x);
                cin >> c;
            }
        }

        int cntF = 0, cntB = 0, rev= -1;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'R') rev *= -1;
            else if (rev == -1) cntF++;
            else cntB++;
        }

        if (cntF+cntB > d.size()) cout << "error" << '\n';
        else {
            for (int i=0; i<cntF; i++) d.pop_front();
            for (int i=0; i<cntB; i++) d.pop_back();
            
            if (rev == 1) reverse(d.begin(), d.end());
            
            cout<<"[";
            for (int i=0; i<d.size(); i++) {
                cout << d[i];
                if (i+1 != d.size()) 
                    cout<<",";
            }
            cout << "]\n";
        }
    }
    return 0;
}