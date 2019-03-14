#include<bits/stdc++.h>
using namespace std;
int searching(int N,int x,int y,vector<vector<int>> graph, vector<vector<int>> &visit){
    if((x<0) || (y<0) || (x>=N) || (y>=N))
        return 0;
    if(visit[x][y]!=0)
        return 0;
    if(graph[x][y]==0)
        return 0;
    else{
        int sum=1;
        visit[x][y]=1;
        sum+=searching(N,x+1,y,graph,visit)+searching(N,x,y+1,graph,visit)+searching(N,x-1,y,graph,visit)+searching(N,x,y-1,graph,visit);
        return sum;
    }
}
int main(){
    int N;
    cin>>N;
    vector<vector<int>> graph(N,vector<int>(N));
    vector<vector<int>> visit(N,vector<int>(N,0));
    vector<int> sum;
    cin.get();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            graph[i][j]=cin.get()-'0';
        }
        cin.get();
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            int tmp=searching(N,i,j,graph,visit);
            if(tmp!=0)
                sum.push_back(tmp);
        }
    }
    sort(sum.begin(),sum.end());
    cout<<sum.size()<<endl;
    for(int i=0;i<sum.size();++i){
        cout<<sum[i]<<endl;
    }
}
