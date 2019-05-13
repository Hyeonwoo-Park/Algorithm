#include<bits/stdc++.h>
using namespace std;
int N,M;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    cin>>N>>M;
    vector<vector<char>> maze(N+1,vector<char>(M+1));
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>maze[i][j];
        }
    }

    vector<vector<bool>> visit(N+1,vector<bool>(M+1,true));
    queue<pair<int,int>> Q;
    Q.emplace(1,1);
    visit[1][1]=false;
    int l=1;
    int d;
    while(!Q.empty()){
        for(int i=Q.size();i>0;--i){
            pair<int,int> tmp=Q.front();
            Q.pop();
            for(int j=0;j<4;++j){
                int X=tmp.first+dx[j];
                int Y=tmp.second+dy[j];

                if(X<=0 || Y<=0 || X>N || Y>M)continue;
                if(visit[X][Y] && maze[X][Y] =='1'){
                    Q.emplace(X,Y);
                    visit[X][Y]=false;
                    if(X==N && Y ==M) d=l+1;
                }
            }
        }
        l++;
    }

    cout<<d;
}
