#include<bits/stdc++.h>
using namespace std;
int stk=0;
int searching(vector<vector<char>> &maze,int x,int y){
    if((x<0)||(y<0)||(x>=16)||(y>=16)){
        return 0;
    }
    if(maze[x][y]=='3'){
        return 1;
    }
    if(maze[x][y]=='1'){
        return 0;
    }
    maze[x][y]='1';
    int sum=0;
    sum+=searching(maze,x+1,y);
    sum+=searching(maze,x,y+1);
    sum+=searching(maze,x-1,y);
    sum+=searching(maze,x,y-1);
    return sum;

}
int main(){
    int t=10;
    for(int T=1;T<=t;T++){
        int a;
        cin>>a;
        vector<vector<char>> maze(16,vector<char>(16));
        pair<int,int> start;
        for(int i=0;i<16;++i){
            for(int j=0;j<16;++j){
                cin>>maze[i][j];
                if(maze[i][j]=='2')
                    start=make_pair(i,j);
            }
        }
        cout<<'#'<<T<<' '<<searching(maze,start.first,start.second)<<endl;
    }
}
