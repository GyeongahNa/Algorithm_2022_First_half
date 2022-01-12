#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int L, C;
int arr[20];
char CList[20];
int isused[20];

void func(int k) {
    
    if (k == L) {
        int cnt = 0;
        for (int i=0; i<L; i++) {
            char c = CList[arr[i]];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }

        if (cnt >= 1 && (L-cnt) >= 2) {
            for (int i=0; i<L; i++)
                printf("%c", CList[arr[i]]);
            printf("\n");;
        }
        return ;
    }   

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<C; i++) {
        if (isused[i]) continue;
        arr[k] = i;
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main() {

    scanf("%d %d", &L, &C);
    for (int i=0; i<C; i++)
        scanf(" %c", &CList[i]);
    sort(CList, CList+C);
    func(0);
    return 0; 
}