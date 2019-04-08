#include<bits/stdc++.h>
using namespace std;
int dX[]={0,1,0,-1};
int dY[]={1,0,-1,0};
int L;
int R;
int dfs(vector<vector<int>>& territory, int x, int y, vector<vector<int>>& visit,int &cnt,int chk){ //cnt는 개방된 총 국경이며, chk는 국경이 개방된 나라의 집합과 국경을 한번이라도 개방하였는지 확인차 사용
    int sum=territory[x][y];
    for(int i=0;i<4;++i){
        int X=x+dX[i];
        int Y=y+dY[i];
        if((X>=0)&&(Y>=0)&&(X<territory.size())&&(Y<territory.size())){             //범위 체크
            if( (abs(territory[X][Y]-territory[x][y]) >= L ) && ( abs(territory[X][Y] - territory[x][y]) <= R ) && (visit[X][Y]==0) ){      //인구수 차이 및 방문 확인
                visit[x][y]=chk;                                                    //국경이 개방 된 곳
                visit[X][Y]=chk;                                                    //국경이 개방 된 곳
                sum += dfs(territory,X,Y,visit,cnt,chk);
                cnt++;                                                              //다른점 확인 시에만 증가 시켜주어서 시작점은 포함되지 않음
            }
        }
    }
    return sum;
}
void migration(vector<vector<int>> &territory, int x,int y,vector<vector<int>> & visit,int chk,int popul){
    if((x<0)||(y<0)||(x>=territory.size())||(y>=territory.size())||visit[x][y]!=chk)
        return;
    visit[x][y]=-1;
    territory[x][y]=popul;
    for(int i=0;i<4;++i){
        int X=x+dX[i];
        int Y=y+dY[i];
        migration(territory,X,Y,visit,chk,popul);
    }
}
int main(){
    int N;
    cin>>N>>L>>R;
    vector<vector<int>> territory (N,vector<int>(N));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>territory[i][j];
        }
    }
    int day=0;
    while(1){
        int chk=1;
        vector<vector<int>> visit (N,vector<int>(N,0));
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int cnt=0;
                if(visit[i][j]==0){                             //한번 인구이동이 끝난 점은 다시 확인 ㄴㄴ
                    int sum=dfs(territory,i,j,visit,cnt,chk);
                    if(cnt){
                        cnt++;                                  //시작점 포함
                        int popul=sum/cnt;                      //인구 이동 후의 인구
                        migration(territory,i,j,visit,chk,popul);
                        chk++;                                  //국경 개방집단의 수
                    }
                }
            }
        }
        if (chk==1)
            break;
        day++;
    }
    cout<<day<<endl;
}
