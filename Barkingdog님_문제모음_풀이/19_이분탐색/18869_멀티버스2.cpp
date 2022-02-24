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
#include <climits>
#include <iostream>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

#define X first
#define Y second

int M, N, re;
vector<vector<int>> origin, sorted, compressed;


void compress() { //좌표 압축
    
    for (int i=0; i<M; i++) { //O(MNlogN)

        vector<int> v(N), tmp(N);
        for (int j=0; j<N; j++) { 
            scanf("%d", &v[j]);
            tmp[j] = v[j];
        }

        sort(tmp.begin(), tmp.end()); 
        sorted.push_back(tmp);
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); 

        vector<int> vcom(N);
        for (int j=0; j<N; j++) { 
            vcom[j] = lower_bound(tmp.begin(), tmp.end(), v[j])-tmp.begin();
        }

        origin.push_back(v);
        compressed.push_back(vcom);
    }
}


void cntbalance() { //균등한 우주 카운트

    vector<vector<int>> dup;

    for (int i=0; i<M; i++) { //O(M^2NlogM)
        for (int j=i+1; j<M; j++) {

            bool isbalanced = true;
            for (int k=0; k<N; k++) { 
                if (compressed[i][k] == compressed[j][k]) continue;
                isbalanced = false;
                break;
            }

            bool issame = true;
            for (int k=0; k<N; k++) {
                if (sorted[i][k] == sorted[j][k]) continue;
                issame = false;
                break;
            }

            if (!issame && isbalanced) re++; //서로 구성이 다르면서 균등할 경우 
            else if (issame && isbalanced) { //서로 구성이 같으면서 균등할 경우
                if (!binary_search(dup.begin(), dup.end(), sorted[i])) re++; 
                dup.push_back(sorted[i]);
            }
        }
    }
}


int main() {

    scanf("%d %d", &M, &N);
    compress();
    cntbalance();
    printf("%d", re);
    return 0;
}