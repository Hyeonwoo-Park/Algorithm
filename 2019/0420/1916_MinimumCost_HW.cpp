#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> city(N+1,vector<int>(N+1,100000001));
    int M;
    cin>>M;
    for(int i=0;i<M;++i){
        int s,e,c;      //start, end, cost
        cin>>s>>e>>c;
        if(c<city[s][e]) city[s][e]=c;
    }

    int s,e;
    cin>>s>>e;
    vector<int> visit(N+1,0);
    int x=s;

    visit[s]=1;
    for(int i=1;i<=N;++i){
        int mini=100000001;
        int x2;
        for(int j=1;j<=N;++j){
            city[s][j]=min(city[s][j],city[s][x]+city[x][j]);
            if(visit[j]==0){
                if(city[s][j]<mini){
                    mini=city[s][j];
                    x2=j;
                }
            }
        }
        visit[x2]=1;
        x=x2;
    }
    cout<<city[s][e];
}
