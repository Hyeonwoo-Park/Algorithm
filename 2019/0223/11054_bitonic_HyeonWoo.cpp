#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
vector<int> dp;
vector<int> dp2;
int down(int i,int N,int len){
    if(i==seq.size())
        return len;
    int A,B;
    A=down(i+1,N,len);
    if(seq[i]<N){
        B=dp[i]+len;
        return max(A,B);
    }
    return A;
}
int up(int i,int N,int len){
    if(i==-1)
        return len;
    int A,B;
    A=up(i-1,N,len);
    if(seq[i]<N){
        B=dp2[i]+len;
        return max(A,B);
    }
    return A;
}
int main(){
    int N,A,len=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A;
        seq.push_back(A);
        dp.push_back(1);
        dp2.push_back(1);
    }
    for(int i=N-1;i>=0;--i)
        dp[i]=down(i,seq[i],1);

    for(int i=0;i<N;i++)
        dp2[i]=up(i,seq[i],1);

    for(int i=0;i<N;i++){
        if(len<dp[i]+dp2[i]-1){
            len=dp[i]+dp2[i]-1;
        }
    }
    cout<<len;
}
