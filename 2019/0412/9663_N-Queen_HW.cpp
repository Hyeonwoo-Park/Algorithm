#include<bits/stdc++.h>
using namespace std;
vector<int> col;
vector<int> backSlash;
vector<int> slash;
int tracking(int x){
    if(x==col.size())
        return 1;
    int sum=0;
    for(int i=0;i<col.size();++i){
        if( ( col[i]==0 ) && (backSlash[ (col.size()-1) - (x-i) ]==0) && ( slash[x+i]==0 ) ){
            col[i]=1;
            backSlash[ (col.size()-1) -(x-i)]=1;
            slash[x+i]=1;

            sum+=tracking(x+1);

            col[i]=0;
            backSlash[ (col.size()-1) - (x-i) ]=0;
            slash[x+i]=0;
        }
    }
    return sum;
}
int main(){
    int N;
    cin>>N;
    col.assign(N,0);
    backSlash.assign(2*N-1,0);
    slash.assign(2*N-1,0);
    cout<<tracking(0)<<endl;
}
