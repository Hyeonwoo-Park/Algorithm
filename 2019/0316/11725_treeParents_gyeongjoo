#include <iostream>
#include <vector>
#include <queue>
#include <cstring> //memset


using namespace std;
const int MAX = 100000+1;

int n;  //노드의 갯수


vector<int> tree[MAX]; //tree
int parents[MAX];    //부모
bool check[MAX];    //방문여부


int main(int argc, const char * argv[]) {
    
    cout << "TAETAE START\n" ;
    
    cin >> n; //노드의 갯수
    
    memset(check,false,sizeof(check));
    
    int u,v;
    
    // tree 를 그래프로 입력받기
    int m = n-1; // 엣지의 갯수
    for(int i=1 ; i<=m ; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // 1을 루트로 지정. 루트의 부모는 0(없음).
    check[1]=true;
    parents[1]=0;
    
    // 큐를 이용한 bfs 시작
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){ //q가 비어있지 않은 동안에. q가 empty 하면 끝남
        int x=q.front();
        q.pop();
        for(int i=0; i<tree[x].size() ; i++){   //tree[x][i]
            if(!check[tree[x][i]]){
                check[tree[x][i]] = true;
                parents[tree[x][i]] = x;
                q.push(tree[x][i]);
            }
        }
    }
    
    cout << '\n';
    
    for(int i=1 ; i<=n ; i++){
        cout << parents[i] << '\n';
    }
    
    cout << "THE END\n" ;
    
    return 0;
}
