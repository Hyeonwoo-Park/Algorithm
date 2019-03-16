#include<bits/stdc++.h>
using namespace std;
int lng;
int end_i;
int searching(vector<vector<pair<int,int>>> &graph,vector<int> &isVisit,int ind,int Dist){
    isVisit[ind]=1;
    //vector<int> maxDis;
    //maxDis.push_back(0);
    int maxD=0;
    int cnt=0;
    for(int i=0;i<graph[ind].size();++i){
        if(isVisit[graph[ind][i].first]==0){
            cnt++;
            int tmp=searching(graph,isVisit,graph[ind][i].first,Dist+graph[ind][i].second);
            if(tmp>maxD)
                maxD=tmp;
            //maxDis.push_back(searching(graph,isVisit,graph[ind][i].first)+graph[ind][i].second);
        }
    }
    if(cnt==0){
        if(Dist>lng){
            lng=Dist;
            end_i=ind;
        }
        return Dist;
    }
    //sort(maxDis.begin(),maxDis.end());
    return maxD;
}
int main(){
    int N;
    lng =0;
    cin>>N;
    vector<vector<pair<int,int>>> tree(N+1);
    vector<int> isVisit(N+1,0);
    vector<int> maxDis;
    for(int i=0;i<N;++i){
        int tmp1,tmp2;
        int ind;
        cin>>ind;
        cin>>tmp1;
        while(tmp1!=-1){
            cin>>tmp2;
            pair<int,int> tmp(tmp1,tmp2);
            tree[ind].push_back(tmp);
            cin>>tmp1;
        }
    }
    searching(tree,isVisit,1,0);
    fill(isVisit.begin(),isVisit.end(),0);
    cout<<searching(tree,isVisit,end_i,0);
}
