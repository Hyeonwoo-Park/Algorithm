#include<bits/stdc++.h>
using namespace std;
vector<int> X={1,0,-1,0};
vector<int> Y={0,1,0,-1};
queue<pair<int,int>> tomato_;
int tomato(vector<vector<int>> &box, int x,int y){
    if(box[x][y]==1){
        for(int i=0;i<4;++i){
            if((x+X[i]>=0)&&(y+Y[i]>=0)&&(x+X[i]<box.size())&&(y+Y[i])<box[0].size()){
                if(box[x+X[i]][y+Y[i]]==0){
                    tomato_.push(make_pair(x+X[i],y+Y[i]));
                    box[x+X[i]][y+Y[i]]=1;
                }
            }
        }
    }
    return abs(box[x][y]);
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> box(M,vector<int>(N));

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>box[i][j];
            if(box[i][j]==1){
                tomato_.push(make_pair(i,j));
            }
        }
    }
    int day=0;
    while(!tomato_.empty()){
        for(int i=tomato_.size();i>0;--i){
            tomato(box,tomato_.front().first,tomato_.front().second);
            tomato_.pop();
        }
        day++;
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(box[i][j]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    if(day==0)
        cout<<0;
    else
        cout<<day-1;
    return 0;
}
