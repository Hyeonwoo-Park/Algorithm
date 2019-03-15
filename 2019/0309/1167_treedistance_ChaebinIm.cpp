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
    BFS(1);
    int start = 1;
    for (int i = 2; i <= N; i++){
        if (dist[i] > dist[start]) start = i;
    }
    BFS(start);
    int ans = dist[1];
    for (int i = 2; i <= N; i++){
        if (ans < dist[i]) ans = dist[i];
    }
    cout << ans << "\n";
    return 0;
}
