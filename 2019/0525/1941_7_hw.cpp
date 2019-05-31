#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int dd[]={5,1,-5,-1};
vector<vector<char>> jari (6,vector<char>(6));
int depth ;
bool chk(int x,vector<int> & visit){
    depth--;
    visit[x] = 0;
    if(depth == 0)
        return true;
    for(int i=0;i<4;++i){
        int X=x/5 +dx[i];
        int Y=x%5 +dy[i];
        int D=x+dd[i];
        if(X<0 ||Y<0|| X>=5 || Y>=5)continue;
        if(visit[D]==0)continue;
        if (chk(D,visit))
            return true;
    }
    return false;
}
int main(){
    vector<vector<int>> visit (6,vector<int>(6,0));
    vector<int> per = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cin>>jari[i][j];
        }
    }
    int sum=0;
    do{
        int Ycnt=0;
        int tmp;
        for(int i=0;i<25;++i){
            int X= i/5;
            int Y= i%5;
            if(per[i] == 1){
                tmp=i;
                if(jari[X][Y] == 'Y')
                Ycnt +=1;
            }
        }
        if(Ycnt >= 4)
            continue;
        vector<int> visit = per;
        depth = 7;
        if(!chk(tmp,visit))
            continue;
        sum++;
    }while(next_permutation(per.begin(),per.end()));
    cout<<sum;
}
