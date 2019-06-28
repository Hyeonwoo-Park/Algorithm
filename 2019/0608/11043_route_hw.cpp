#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> arr;
void searching(int s,int d){
    arr[s][d] = 1;
    for(int i=0;i<N;++i)
        if(arr[s][i] == 0 && arr[d][i] == 1 )
            searching(s,i);
}
int main(){
    cin>>N;
    arr.assign(N,vector<int>(N));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i<N;++i){
        for(int j=0;j<N;++j){
            if(arr[i][j] == 1){
                searching(i,j);
            }
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<< arr[i][j] <<' ';
        }
        cout<<'\n';
    }
}
