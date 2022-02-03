#include <iostream>
using namespace std;

int N;
int arr[10005];

int main() {

    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        arr[x]++;
    }

    for (int i=1; i<=10000; i++) {
        if (!arr[i]) continue;
        for (int j=0; j<arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}