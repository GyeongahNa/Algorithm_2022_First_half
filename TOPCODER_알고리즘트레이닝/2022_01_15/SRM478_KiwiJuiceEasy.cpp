#include <cstdio>
#include <cstring>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

class KiwiJuiceEasy {

public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {

        for (int i=0; i<fromId.size(); i++) {

            int mx = capacities[toId[i]]-bottles[toId[i]];

            if (bottles[fromId[i]] >= mx) {
                bottles[toId[i]] += mx;
                bottles[fromId[i]] -= mx;
            }
            else {
                bottles[toId[i]] += bottles[fromId[i]];
                bottles[fromId[i]] = 0;
            }
        }
        return bottles;
    }
};

int main() {

    KiwiJuiceEasy kiwi;
    vector<int> re;

    re = kiwi.thePouring({20, 20}, {5, 8}, {0}, {1});
    for (int i=0; i<re.size(); i++) 
        cout<<re[i]<<" ";
    cout<<endl;

    re = kiwi.thePouring({10, 10}, {5, 8}, {0}, {1});
    for (int i=0; i<re.size(); i++) 
        cout<<re[i]<<" ";
    cout<<endl;  

    re = kiwi.thePouring({30, 20, 10}, {10, 5, 5}, {0, 1, 2}, {1, 2, 0});
    for (int i=0; i<re.size(); i++) 
        cout<<re[i]<<" ";
    cout<<endl;    
}
