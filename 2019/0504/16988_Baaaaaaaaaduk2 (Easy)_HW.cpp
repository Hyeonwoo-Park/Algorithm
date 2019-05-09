#include<bits/stdc++.h>
using namespace std;
int max_=0;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m;
int chk(vector<vector<int>> &baduk, int x,int y,vector<vector<bool>> &visit){
    visit[x][y]=false;
    int sum = 1;
    bool flag =true;
    for(int i=0;i<4;++i){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X<0 || Y<0 || X >= n || Y >= m)continue;
        if( baduk[X][Y] == 0 )
            flag = false;
        if(visit[X][Y] && baduk[X][Y] == 2 ){
            int tmp = chk(baduk,X,Y,visit);
            if( tmp == 0 )
                flag = false;
            sum += tmp;
        }
    }
    if(flag)
        return sum;
    else
        return 0;
}
int counting(vector<vector<int>> &baduk,vector<vector<bool>>& visit){
    int sum=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(baduk[i][j]==2 && visit[i][j])
                sum+=chk(baduk,i,j,visit);
        }
    }
    return sum;
}
void searching(vector<vector<int>> &baduk,int cnt){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(baduk[i][j]==0){
                baduk[i][j]=1;
                if(cnt){
                    searching(baduk,cnt-1);
                }
                else{
                    vector<vector<bool>> visit(n,vector<bool> (m,true));
                    max_=max(max_,counting(baduk,visit));
                }
                baduk[i][j]=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<vector<int>> baduk(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>baduk[i][j];
        }
    }
    searching(baduk,1);
    cout<<max_;
}
