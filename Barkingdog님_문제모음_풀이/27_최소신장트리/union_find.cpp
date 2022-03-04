#include <vector>
#include <iostream>
using namespace std;

int N = 10;
vector<int> nrank(10, 1);
vector<int> parent(10, 0);

// 초기화: 모든 정점이 다른 집합에 존재하도록 설정
void initialize() {
    
    for (int i=1; i<=N; i++)
        parent[i] = i; 
}

// find: 정점 u의 루트 노드를 반환
// 경로 압축을 위해 재귀적으로 구한 루트 노드 번호를 parent[u]에 저장
int find(int u) {

    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

// merge(union): 정점 u와 정점 v가 속한 집합이 다른 경우, 두 집합을 합함
void merge(int u, int v) {

    u = find(u);
    v = find(v);

    if (u == v) return ; // 속한 집합이 같다면 합칠 필요 없음

    // 높이(nrank)가 더 큰 값의 루트 노드를 v에 저장
    if (nrank[u] > nrank[v]) swap(u, v);

    // 높이가 낮은 트리를 높이가 높은 트리에 연결
    parent[u] = v;

    // 두 트리의 높이가 같다면 결과 트리의 높이를 1 증가
    if (nrank[u] == nrank[v]) nrank[v]++;
}

int main() {

    initialize();
    merge(1, 2);
    merge(2, 3);
    merge(3, 4);
    merge(4, 5);
    merge(5, 6);
    merge(6, 7);
    merge(7, 8);
    merge(8, 9);
    merge(9, 10);

    for (int i=1; i<=N; i++) cout<<parent[i]<<" ";
    cout<<endl;
    return 0;
}