#include <iostream>
using namespace std;

int n = 10;
int arr[10] = {30, 10, 60, 50, 40, 90, 20, 70, 80, 0};

void selectionSort() {

    for (int i=n-1; i>0; i--) {
        int maxidx = 0;
        for (int j=1; j<=i; j++) {
            if (arr[maxidx] < arr[j]) maxidx = j;
        }
        swap(arr[maxidx], arr[i]);
    }
}

void printarr() {

    for (int i=0; i<n; i++) 
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {

    selectionSort();
    printarr();
    return 0;
}