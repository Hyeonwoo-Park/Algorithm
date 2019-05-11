#include<bits/stdc++.h>
#define D 1000000000

using namespace std;
vector<vector<vector<long long>>> dp(1025, vector<vector<long long>> (101, vector<long long>(10,-1)));


long long f(int N,int x,vector<int> visit){
    int a=1;
    int k=0;
    visit[x]=1;
    for(int i=0;i<10;++i){
        k+=(a*visit[i]);
        a*=2;
    }
    if(dp[k][N][x]!=-1)
        return dp[k][N][x];

    if(N==0){
        for(int i=0;i<=9;++i)
            if(visit[i]==0) return 0;

        return 1;
    }
    long long sum=0;
    if(x<9)
        sum +=f(N-1,x+1,visit)%D;
    if(x>0)
        sum +=f(N-1,x-1,visit)%D;
    dp[k][N][x] = sum%D;
    return dp[k][N][x];
}

int main(){
    int Testcase;
    cin>>Testcase;
    for(int T=1;T<=Testcase;++T){
        int N;
        cin>>N;
        long long sum=0;
        vector<int> visit(10,0);
        for(int i=1;i<=9;++i)
            sum+=f(N-1,i,visit)%D;
        cout<<'#'<<T<<' '<<sum%D<<endl;
    }

}
