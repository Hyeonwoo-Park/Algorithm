#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<vector<int>> com(N+1,vector<int>(N+1,0));
    int M;
    cin>>M;
    for(int i=0;i<M;++i){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        com[tmp1][tmp2]=1;
        com[tmp2][tmp1]=1;
    }
    vector<int> visit(N+1,0);
    queue<int> Q;
    Q.push(1);
    visit[1]=1;
    int cnt=0;
    while(!Q.empty()){
        for(int i=Q.size();i>0;--i){
            int tmp=Q.front();
            Q.pop();
            for(int j=1;j<=N;++j){
                if(visit[j]==0 && com[tmp][j] ==1){
                    Q.push(j);
                    visit[j]=1;
                    cnt++;
                }
            }
        }

    }
    cout<<cnt<<endl;
}
