#include <vector>
#include <iostream>
using namespace std;

//순열: 순서 O, 중복 X
//nPr = n!/(n-r)!

#define n 3
#define r 2

int arr[30];
int check[30];

void printarr() {

    for (int i=0; i<r; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void permutation(int k) {

    if (k == r) {
        printarr();
        return ;
    }

    for (int i=0; i<n; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[k] = i;
        permutation(k+1);
        check[i] = false;
    }
}

int main() {

    permutation(0);
    return 0;
}