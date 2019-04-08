#include<bits/stdc++.h>
using namespace std;
int dX[]={0,1,0,-1};
int dY[]={1,0,-1,0};
int max_=0;
void spread(vector<vector<int>> &lab, int x,int y,vector<vector<int>> &visit){
    lab[x][y]=2;
    visit[x][y]=1;
    for(int i=0;i<4;++i){
        int X=x+dX[i];
        int Y=y+dY[i];
        if( (X>=0) && (Y>=0) && (X<lab.size()) && (Y<lab[0].size()) ){      //범위 체크
            if( (lab[X][Y]==0))                                             //빈칸이거나 바이러스면
                if(visit[X][Y]==0)                                          //방문 체크
                    spread(lab,X,Y,visit);
        }
    }
}
int wall(vector<vector<int>> lab,int depth){
    for(int i=0;i<lab.size();++i){
        for(int j=0;j<lab[0].size();++j){
            if(lab[i][j]==0){
                lab[i][j]=1;
                if(depth==3){//벽 세개가 다 세워 졌으면
                    vector<vector<int>> visit(lab.size(),vector<int>(lab[0].size(),0));
                    vector<vector<int>> lab_tmp=lab;
                    for(int k=0;k<lab.size();++k){
                        for(int l=0;l<lab[0].size();++l){
                            if( (lab[k][l]==2) )
                                spread(lab_tmp,k,l,visit);
                        }
                    }
                    ////바이러스 확산


                    int tmp=0;
                    for(int k=0;k<lab.size();++k){
                        for(int l=0;l<lab[0].size();++l){
                            if(lab_tmp[k][l]==0)
                                tmp++;
                        }
                    }
                    ////// 안전구역 카운팅

                    if(tmp>max_){
                        max_=tmp;
                    }
                }
                else{
                    wall(lab,depth+1);
                }
                lab[i][j]=0;
            }
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> lab(N,vector<int>(M));
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>lab[i][j];
        }
    }
    wall(lab,1);
    cout<<max_<<endl;
}
