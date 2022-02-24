#include <iostream>
using namespace std;

int N;
int sz;
int heap[100005];

void push(int x){

    heap[++sz] = x;

    int tmp = sz;
    while (tmp > 1 && heap[tmp/2] > heap[tmp]) {
        swap(heap[tmp/2], heap[tmp]);
        tmp /= 2;
    }
}

int top(){
    if (sz == 0) return 0;
    return heap[1];
}

void pop(){

    if (sz == 0) return ;
    
    int x = 1;
    swap(heap[x], heap[sz--]);
    while ((2*x <= sz && heap[x] > heap[2*x]) || (2*x+1 <= sz && heap[x] > heap[2*x+1])) {
        
        if ((2*x+1 > sz) || (heap[2*x] <= heap[2*x+1])) {
            swap(heap[x], heap[2*x]);
            x = 2*x;
        }
        else {
            swap(heap[x], heap[2*x+1]);
            x = 2*x+1;
        }
    }
}

int main() {

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        if (!x) {
            printf("%d\n", top());
            pop();
        }
        else push(x);
    }
    return 0;
}