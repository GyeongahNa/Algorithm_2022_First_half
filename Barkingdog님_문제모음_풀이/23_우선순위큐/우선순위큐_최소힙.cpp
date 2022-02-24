#include <iostream>
using namespace std;

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

    swap(heap[1], heap[sz--]);

    int x = 1;
    while (2*x <= sz) { //자식이 있는지 확인
        int lc = 2*x, rc = 2*x+1;
        int mn_ch = lc;
        if (rc <= sz && heap[rc] < heap[lc]) mn_ch = rc;
        if (heap[x] <= heap[mn_ch]) break;
        swap(heap[x], heap[mn_ch]); 
        x = mn_ch;
    }
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}