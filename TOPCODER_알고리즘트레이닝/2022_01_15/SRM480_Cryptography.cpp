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

class Cryptography {

public:
    long long encrypt(vector<int> numbers) {

        long long mul = 1;
        for (int i=0; i<numbers.size(); i++)
            mul *= numbers[i];

        long long mx = mul;
        for (int i=0; i<numbers.size(); i++)
            mx = max(mx, mul+mul/(long long)numbers[i]);
        return mx;
    }
};

int main() {

    Cryptography cry;
    long long re;

    re = cry.encrypt({1, 2, 3});
    cout<<re<<endl;

    re = cry.encrypt({1,3,2,1,1,3});
    cout<<re<<endl;

    re = cry.encrypt({1000,999,998,997,996,995});
    cout<<re<<endl;

    re = cry.encrypt({1,1,1,1});
    cout<<re<<endl;
}
