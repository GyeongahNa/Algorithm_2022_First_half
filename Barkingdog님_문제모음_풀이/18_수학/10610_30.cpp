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
#include <numeric>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

string s;
vector<int> vnum;

int main() {

    char str[100005];
    scanf("%s", str);
    s = string(str);

    for (int i=0; i<s.size(); i++) vnum.push_back(s[i]-'0');
    sort(vnum.begin(), vnum.end(), greater<>());

    int tot = accumulate(vnum.begin(), vnum.end(), 0);
    if (tot%3 == 0 && vnum[(int)vnum.size()-1] == 0) {
        for (int i=0; i<vnum.size(); i++)
            printf("%d", vnum[i]);
    }
    else printf("-1");
    return 0;
}

/* 
배수 판정법 - 어떤 수의 모든 자릿수를 더했을 때 3의 배수이면, 어떤 수는 3의 배수임
문제에서는 30의 배수가 되는지 확인하라고 했으므로,
내림차순으로 정렬하였을 때 제일 마지막 자리에 0이 있는지 확인하고(10의 배수 확인)
그 앞자리 숫자의 자릿수들을 모두 더해 그 값이 3의 배수인지 확인
+ 가장 큰 수를 출력하라고 했으므로 내림차순으로 정렬한 결과 출력
*/