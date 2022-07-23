#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
using sll = pair<string, ll>;
using ll3 = tuple<ll, ll, ll>;

#define X first
#define Y second

long long T, n, m, p, q, k, t, s, d;
string c, name;
stack<char> st;
char e;

map<string, ll3> carInfo;
map<string, ll> price;
map<string, string> car;
map<string, stack<char>> record;

void init() {

    carInfo.clear();
    price.clear();
    car.clear();
    record.clear();
}

void setCarInfo() {

    for (int i=0; i<n; i++) {
        cin >> c;
        cin >> p >> q >> k;
        carInfo[c] = {p, q, k};
    }
}

void setRecordInfo() {

    for (int i=0; i<m; i++) {
        cin >> t >> name >> e;
        if (e == 'p') {
            cin >> c;
            if (price[name] == -1) continue;
            if (!record[name].empty()) price[name] = -1;
            else {
                price[name] += get<1>(carInfo[c]);
                record[name].push('p');
                car[name] = c;
            } 
        }
        else if (e == 'a') {
            cin >> s;
            if (price[name] == -1) continue;
            if (record[name].empty() || record[name].top() != 'p') price[name] = -1;
            else {
                price[name] += get<0>(carInfo[car[name]])*s/100;
                if (get<0>(carInfo[car[name]])*s%100 != 0) price[name] += 1;
            }
        }
        else { //(e == 'r)
            cin >> d;
            if (price[name] == -1) continue;
            if (record[name].empty() || record[name].top() == 'r') price[name] = -1; 
            else {
                price[name] += get<2>(carInfo[car[name]])*d;
                while (!record[name].empty()) record[name].pop();
            }
        }
    }
    
    for (auto [name, st] : record) {
        if (price[name] != -1 && !st.empty()) price[name] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        init();
        cin >> n >> m;
        setCarInfo();
        setRecordInfo();
        
        vector<sll> v;
        for (auto [name, p] : price) v.push_back({name, p});
        sort(v.begin(), v.end());

        for (auto [name, p] : v) {
            cout<<name<<" ";
            if (p == -1) cout<<"INCONSISTENT\n";
            else cout<<p<<"\n";
        }
    }
    return 0;
}