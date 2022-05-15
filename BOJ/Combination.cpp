#include <vector>
#include <iostream>
using namespace std;

//조합: 순서 X, 중복 X
//nCr = n!/(n-r)!r!

#define n 3
#define r 2

int arr[30];

void printarr() {

    for (int i=0; i<r; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void combination(int k) {

    if (k == r) {
        printarr();
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1]+1;
    for (int i=st; i<n; i++) {
        arr[k] = i;
        combination(k+1);
    }
}

int main() {

    combination(0);
    return 0;
}