#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dp1;
    vector<int> dp2;
    vector<int> wine;
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int w;
        cin>>w;
        wine.push_back(w);
        dp1.push_back(-1);
        dp2.push_back(-1);
    }
    dp1[N-1]=wine[N-1];
    dp2[N-1]=wine[N-1];
    if(N>=2){
        dp1[N-2]=wine[N-2];
        dp2[N-2]=wine[N-1]+wine[N-2];
    }
    for(int i=N-3;i>=0;--i){
        dp1[i]=max(max(dp1[i+2],dp2[i+2])+wine[i],dp2[i+1]);
        dp2[i]=wine[i]+dp1[i+1];
    }
    cout<<max(dp1[0],dp2[0]);
}
