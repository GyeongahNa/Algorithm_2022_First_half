#include <vector>
#include <iostream>
using namespace std;

//중복조합: 순서 X, 중복 O
// nHr = (n+r-1)Cr

#define n 3
#define r 2

int arr[30];

void printarr() {

    for (int i=0; i<r; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void CombinationWithRep(int k) {

    if (k == r) {
        printarr();
        return ;
    }

    int st = 0;
    if (k != 0) st = arr[k-1];
    for (int i=st; i<n; i++) {
        arr[k] = i;
        CombinationWithRep(k+1);
    }
}

int main() {

    CombinationWithRep(0);
    return 0;
}