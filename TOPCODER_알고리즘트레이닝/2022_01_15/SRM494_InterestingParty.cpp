#include <cstdio>
#include <cstring>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

// class InterestingParty {

// public:
//     int bestInvitation(vector<string> first, vector<string> second) {

//         int mx = 0;

//         for (int i=0; i<first.size(); i++) {
//             int fcnt = 0, scnt = 0;
//             for (int j=0; j<first.size(); j++) {
//                 if (first[i] == first[j]) fcnt++;
//                 if (first[i] == second[j]) fcnt++;
//                 if (second[i] == first[j]) scnt++;
//                 if (second[i] == second[j]) scnt++;
//             }
//             mx = max(mx, fcnt);
//             mx = max(mx, scnt);
//         }
//         return mx;
//     }
// };

class InterestingParty {

public:
    int bestInvitation(vector<string> first, vector<string> second) {

        map<string, int> dic;

        for (int i=0; i<first.size(); i++) {
            dic[first[i]] = 0;
            dic[second[i]] = 0;
        }

        for (int i=0; i<first.size(); i++) {
            dic[first[i]]++;
            dic[second[i]]++;
        }

        int ans = 0;
        map<string, int>::iterator it;

        for (it = dic.begin(); it != dic.end(); it++) {
            ans = max(ans, (*it).second);
        }

        return ans;
    }
};

int main() {

    InterestingParty party;
    int re;

    re = party.bestInvitation(
        {"fishing", "gardening", "swimming", "fishing"},
        {"hunting", "fishing", "fishing", "biting"});
    cout<<re<<endl;
    
    re = party.bestInvitation(
        {"variety", "diversity", "loquacity", "courtesy"},
        {"talking", "speaking", "discussion", "meeting"});
    cout<<re<<endl;

    re = party.bestInvitation(
        {"snakes", "programming", "cobra", "monty"},
        {"python", "python", "anaconda", "python"});
    cout<<re<<endl;

    re = party.bestInvitation(
        {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"},
        {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"});
    cout<<re<<endl;
}

/*map을 활용한 풀이법이 훨씬 깔끔*/
/*map이 파이썬 딕셔너리 같은 건가?*/