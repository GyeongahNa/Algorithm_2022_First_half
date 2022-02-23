#include <cstdio>
#include <cstring>
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
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int T, n, d;
char c;

int main() {

    scanf("%d", &T);
    while (T--) {
        multiset<int> s;
        scanf("%d", &n);
        while (n--) {
            scanf(" %c %d", &c, &d);
            if (c == 'I') s.insert(d);
            else if (s.size() < 1) continue;
            else if (d == 1) s.erase(--s.end());
            else s.erase(s.begin());
        }
        if (s.size() == 0) printf("EMPTY\n");
        else printf("%d %d\n", *(--s.end()), *s.begin());
    }
    return 0;
}