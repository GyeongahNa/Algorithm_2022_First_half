#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

//서브테스크 1
// unsigned long long N, num, cnt;
// string K;

// int main() {

//     cin >> N >> K;
//     for (int i=0; i<N; i++) {
//         if (K[i]== '1') num |= (1<<(N-1-i));
//     }

//     cnt = 0;
//     while (num) {
//         cnt++;
//         num = num-(num&((~num)+1));
//     }
//     cout<<cnt;
//     return 0;
// }

//서브테스크 2
// (~K)+1 = -K
// K&(-K) 값이 1인 최하위 비트
// K-(값이 1인 최하위 비트) 연산을 계속하는 것이므로 원래 이진수에서 1의 개수를 찾으면 됨

int N, cnt;
string s;

int main() {

    cin >> N >> s;
    for (auto x : s) if (x == '1') cnt++;
    cout<<cnt;
    return 0;
}