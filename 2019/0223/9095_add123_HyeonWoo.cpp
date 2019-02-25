#include<bits/stdc++.h>
using namespace std;
vector<int> dp(12,0);
int divide(int T){
    if(T==0)
        return 1;
    if(dp[T]!=0)
        return dp[T];
    int sum=0;
    if(T>=1)
        sum+=divide(T-1);
    if(T>=2)
        sum+=divide(T-2);
    if(T>=3)
        sum+=divide(T-3);
    return sum;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;++i){
        int T;
        cin>>T;
        dp[T]=divide(T);
        cout<<divide(T)<<endl;
    }
}
