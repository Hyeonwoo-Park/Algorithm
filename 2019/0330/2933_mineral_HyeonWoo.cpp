#include<bits/stdc++.h>
using namespace std;
int chk;
int in;
int ax;
void searching(vector<vector<int>>&mineral,vector<vector<int>> &visit,int x, int y,int t){
    if((x<=0)||(y<=0)||(x>=mineral.size())||(y>=mineral[1].size()))
        return;
    if(visit[x][y]!=0)
        return;
    if(mineral[x][y]==0)
        return;
    if(in>y)
        in=y;
    if(ax<y)
        ax=y;
    if(x==mineral.size()-1)
        chk=t;
    visit[x][y]=t;
    searching(mineral,visit,x+1,y,t);
    searching(mineral,visit,x,y+1,t);
    searching(mineral,visit,x-1,y,t);
    searching(mineral,visit,x,y-1,t);
}
int main(){
    int R,C;
    cin>>R>>C;
    vector<vector<int>> mineral(R+1,vector<int>(C+1,0));
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            char tmp;
            cin>>tmp;
            if(tmp=='x')
                mineral[i][j]=1;
        }
    }
    int N;
    cin>>N;
    int turn=1;
    for(int i=0;i<N;++i){
        chk=0;
        vector<vector<int>> visit(R+1,vector<int>(C+1,0));
        int X;
        cin>>X;
        X=R+1-X;
        int j;
        if(turn==1)
            j=1;
        if(turn==-1)
            j=C;
        for(;(j<=C)&&(j>=0);j+=turn){
            in=C+1;
            ax=1;
            int v=1;
            if(mineral[X][j]==1){
                mineral[X][j]=0;
                if((X+1<=R)&&(mineral[X+1][j]==1))
                    searching(mineral,visit,X+1,j,v);
                else if((j+1<=C)&&(mineral[X][j+1]==1))
                    searching(mineral,visit,X,j+1,v);
                else if((X-1>0)&&(mineral[X-1][j]==1))
                    searching(mineral,visit,X-1,j,v);
                else if((j-1>0)&&(mineral[X][j-1]==1))
                    searching(mineral,visit,X,j-1,v);
            }
            else
                continue;
            if(chk==1){                                         //바닥에 닿는 클러스터를 찾앗을때.
                in=C+1;
                ax=1;
                v++;
                if((X+1<=R)&&(mineral[X+1][j]==1)&&(visit[X+1][j]==0))
                    searching(mineral,visit,X+1,j,v);
                else if((j+1<=C)&&(mineral[X][j+1]==1)&&(visit[X][j+1]==0))
                    searching(mineral,visit,X,j+1,v);
                else if((X-1>0)&&(mineral[X-1][j]==1)&&(visit[X-1][j]==0))
                    searching(mineral,visit,X-1,j,v);
                else if((j-1>0)&&(mineral[X][j-1]==1)&&(visit[X][j+1]==0))
                    searching(mineral,visit,X,j-1,v);
                else break;
            }
            if(chk==2) break;
            //최소높이 구하는 부분
            int h=R+1;
            for(int k=in;k<=ax;k++){
                int xCounting=0;
                for(int l=1;l<=R;++l){
                    if(visit[R+1-l][k]==v){
                        if(h>(l-1-xCounting))
                            h=l-1-xCounting;
                        break;
                    }
                    if(mineral[R+1-l][k]==1)
                        xCounting=l;
                }
            }
            for(int k=R;k>=1;--k){
                for(int l=C;l>=1;--l){
                    if(visit[k][l]==v){
                        mineral[k][l]=0;
                        mineral[k+h][l]=1;
                    }
                }
            }
            break;
        }
        turn = -turn;
    }
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            if(mineral[i][j]==0)
                cout<<".";
            else
                cout<<"x";
        }
        cout<<endl;
    }
}
