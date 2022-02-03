#include <iostream>
using namespace std;

int n = 10;
int arr[10] = {30, 10, 60, 50, 40, 90, 20, 70, 80, 0};

void quickSort(int st, int en) {
    
    if (en <= st+1) return; 
    
    int pivot = arr[st];
    int l = st+1, r = en-1;
    while (1) {
        while (l <= r && arr[l] <= pivot) l++;
        while (l <= r && arr[r] >= pivot) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quickSort(st, r);
    quickSort(r+1, en);
}

void printarr() {

    for (int i=0; i<n; i++) 
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {

    quickSort(0, n);
    printarr();
    return 0;
}