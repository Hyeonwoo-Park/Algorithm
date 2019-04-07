#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> schedule(N+1,vector<int>(2));
    vector<int> profit(N+2,0);
    for(int i=1;i<N+1;++i){
        cin>>schedule[i][0]>>schedule[i][1];
    }
    for(int i=N;i>0;--i){
        if(schedule[i][0] + i > N+1)
            profit[i]=profit[i+1];
        else{
            profit[i]=max(profit[i+1],schedule[i][1]+profit[i+schedule[i][0]]);
        }
    }
    cout<<profit[1]<<endl;
}
