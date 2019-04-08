#include<bits/stdc++.h>
using namespace std;
int dX[]={0,1,0,-1};
int dY[]={1,0,-1,0};
int L;
int R;
int dfs(vector<vector<int>>& territory, int x, int y, vector<vector<int>>& visit,int &cnt,int chk){ //cnt�� ����� �� �����̸�, chk�� ������ ����� ������ ���հ� ������ �ѹ��̶� �����Ͽ����� Ȯ���� ���
    int sum=territory[x][y];
    for(int i=0;i<4;++i){
        int X=x+dX[i];
        int Y=y+dY[i];
        if((X>=0)&&(Y>=0)&&(X<territory.size())&&(Y<territory.size())){             //���� üũ
            if( (abs(territory[X][Y]-territory[x][y]) >= L ) && ( abs(territory[X][Y] - territory[x][y]) <= R ) && (visit[X][Y]==0) ){      //�α��� ���� �� �湮 Ȯ��
                visit[x][y]=chk;                                                    //������ ���� �� ��
                visit[X][Y]=chk;                                                    //������ ���� �� ��
                sum += dfs(territory,X,Y,visit,cnt,chk);
                cnt++;                                                              //�ٸ��� Ȯ�� �ÿ��� ���� �����־ �������� ���Ե��� ����
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
                if(visit[i][j]==0){                             //�ѹ� �α��̵��� ���� ���� �ٽ� Ȯ�� ����
                    int sum=dfs(territory,i,j,visit,cnt,chk);
                    if(cnt){
                        cnt++;                                  //������ ����
                        int popul=sum/cnt;                      //�α� �̵� ���� �α�
                        migration(territory,i,j,visit,chk,popul);
                        chk++;                                  //���� ���������� ��
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
