#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> tree(N+2);
    vector<int> parents(N+2,0);
    for(int i=0;i<N-1;++i){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        for(int i=Q.size();i>0;--i){
            for(int j=0;j<tree[Q.front()].size();++j){
                if(parents[tree[Q.front()][j]]==0){
                    Q.push(tree[Q.front()][j]);
                    parents[tree[Q.front()][j]]=Q.front();
                }
            }
            Q.pop();
        }
    }
    for(int i=2;i<N+1;++i){
        cout<<parents[i]<<'\n';
    }
}
