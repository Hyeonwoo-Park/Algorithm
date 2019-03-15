#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100001

int N;
int ans;
int dist[MAX];
bool chk[MAX];
vector<pair<int,int>> a[MAX]; // first : 정점, second : 비용

//BFS는 distance[]에 원하는 숫자를 넣으려는 노력.
void BFS(int start){
    fill(chk, chk + MAX, false);
    fill(dist, dist + MAX, 0);
    queue<int> q;
    chk[start] = true;
    q.push(start);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int i = 0; i < a[node].size(); i++){
            int next_node = a[node][i].first; // first값은 연결된 정점
            if (chk[next_node] == false){
                dist[next_node] = dist[node] + a[node][i].second; // 비용 저장
                q.push(next_node);
                chk[next_node] = true;
            }
        }
    }
}
//input 함수는 그냥 입력받는 함수.
void Input(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;
        int v = 0, d = 0;
        while (true){
            cin >> v; if (v == -1) break;
            cin >> d;
            a[x].push_back(make_pair(v,d)); // a[i].first : i와 연결된 정점, a[i].second : 가중치
        }
    }
}

int main(){
    Input();
    //root를 뭘로 잡기 애매하니, 일단 1로 잡고 진행하겠다. 그리고 거기서 얻은 정보를 바탕으로 뒤에 한번 더 BFS를 하겠다.
    BFS(1);
    int start = 1;
    //root를 가장 큰 거리정보를 가진 녀석으로 변경.
    for (int i = 2; i <= N; i++){
        if (dist[i] > dist[start]) start = i;
    }
    //새로운 루트로 다시 실행.
    BFS(start);
    int ans = dist[1];
    for (int i = 2; i <= N; i++){
        if (ans < dist[i]) ans = dist[i];
    }
    cout << ans << "\n";
    return 0;
}
