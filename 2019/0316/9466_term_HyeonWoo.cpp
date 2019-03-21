#include<bits/stdc++.h>
using namespace std;
int term(vector<int> &team,vector<int> &visit,queue<int>&cycle,int st,int ed){
    if(st==ed){             //������ cycle
        return 0;
    }
    cycle.push(ed);
    if(visit[ed]==1){       //cycle �� ���� �� ���
        int cnt=0;
        while(cycle.front()!=ed){           //cycle�� ã�Ƽ�
            cycle.pop();
            cnt++;
        }
        while(!cycle.empty()){
            team[cycle.front()]=0;            //���� 0���� ����.
            cycle.pop();
        }
        return cnt;
    }
    visit[ed]=1;
    return term(team,visit,cycle,st,team[ed]);
}
int main(){
    int testcase;
    cin>>testcase;
    for(int i=0;i<testcase;++i){
        int N,sum=0;
        cin>>N;
        vector<int> team(N+1);
        for(int j=1;j<N+1;++j){
            cin>>team[j];
        }
        vector<int> visit(N+1,0);

        for(int j=1;j<N+1;++j){
            queue<int> cycle;
            if(visit[j]==0){
                cycle.push(j);
                sum+=term(team,visit,cycle,j,team[j]);
                visit[j]=1;
            }
        }
        cout<<sum<<endl;;
    }
}
