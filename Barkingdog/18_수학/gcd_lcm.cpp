#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

//GCD(Greatest Common Divisor) - 최대공약수
//유클리드 호제법
//gcd(a, b) = gcd(b, a%b)
//b자리가 0이 될 때 a에 오는 수가 GCD

//LCM(Least Common Multiple) - 최소공배수
//a*b = gcd(a, b)*lcm(a, b)
//lcm(a, b) = a*b/gcd(a, b)
//int overflow를 방지하기 위해서 a/gcd(a, b)*b로 계산

int gcd_recur(int a, int b) {
    if (b == 0) return a;
    return gcd_recur(b, a%b);
}

int gcd_while(int a, int b) {

    while (b != 0) {
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int lcm(int a, int b) {
    return a/gcd_recur(a, b)*b;
}

int main() {

    cout<<"재귀를 이용한 gcd"<<endl;
    cout<<gcd_recur(10, 5)<<endl;
    cout<<gcd_recur(20, 10)<<endl;
    cout<<gcd_recur(36, 18)<<endl;
    cout<<gcd_recur(36, 40)<<endl<<endl;

    cout<<"while문을 이용한 gcd"<<endl;
    cout<<gcd_while(10, 5)<<endl;
    cout<<gcd_while(20, 10)<<endl;
    cout<<gcd_while(36, 18)<<endl;
    cout<<gcd_while(36, 40)<<endl<<endl;

    cout<<"lcm"<<endl;
    cout<<lcm(10, 5)<<endl;
    cout<<lcm(20, 10)<<endl;
    cout<<lcm(36, 18)<<endl;
    cout<<lcm(36, 40)<<endl;  
}