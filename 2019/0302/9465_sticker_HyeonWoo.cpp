#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int M;
        cin>>M;
        vector<vector<int>> stk(2,vector<int>(M,0));
        vector<vector<int>> dp(2,vector<int>(M,0));
        for(int j=0;j<M;j++){
            cin>>stk[0][j];
        }
        for(int j=0;j<M;j++){
            cin>>stk[1][j];
        }
        dp[0][0]=stk[0][0];
        dp[1][0]=stk[1][0];
        dp[0][1]=stk[0][1]+stk[1][0];
        dp[1][1]=stk[1][1]+stk[0][0];
        for(int j=2;j<M;j++){
            dp[0][j]=stk[0][j]+max(dp[1][j-1],dp[1][j-2]);
            dp[1][j]=stk[1][j]+max(dp[0][j-1],dp[0][j-2]);
        }
        cout<<max(dp[0][M-1],dp[1][M-1])<<endl;
    }
}
