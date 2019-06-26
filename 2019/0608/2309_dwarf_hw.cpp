#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dwarf(9);
    vector<int> p={0,0,1,1,1,1,1,1,1};
    for(int i=0;i<9;++i){
        cin>>dwarf[i];
    }
    sort(dwarf.begin(),dwarf.end());
    do{
        int sum =0;
        for(int i=0;i<9;++i){
            sum+=dwarf[i] * p[i];
        }
        if(sum==100) break;
    }while(next_permutation(p.begin(),p.end()));
    for(int i=0;i<9;++i){
        if(p[i] == 1)
            cout<<dwarf[i]<<'\n';
    }




}
