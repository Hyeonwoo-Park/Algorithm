#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

bool visited[MAX];
vector<int> tree[MAX];
int parent[MAX];

void dfs(int n){
    visited[n] = true;
    for(int i = 0; i < tree[n].size(); i++){
        int next = tree[n][i];
        if(!visited[next]){
            parent[next] = n;
            dfs(next);
        }
    }
}

int main(){
    //cin 속도 향상 위해
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n;
    cout << "start" << endl;
    cin >> n;
    //부모 자식 관계를 의미하는 숫자를 입력받음. for문을 쓴건, 예를 들어 n이 10이면 간선의 갯수는 9개가 될수밖에없음.
    for(int i = 0; i < n-1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    //tree[1] = {6, 4}
    //tree[2] = {4}
    //tree[3] = {6, 5}
    //tree[4] = {1, 2, 7}
    //tree[5] = {3}
    //tree[6] = {1, 3}
    //tree[7] = {4}
    
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << parent[i] << endl;
    }
    
    return 0;
}
