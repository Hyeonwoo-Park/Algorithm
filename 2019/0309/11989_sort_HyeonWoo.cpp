#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int>counter(10001,0);
    int N;
    cin>>N;
    int tmp;
    for(int i=0;i<N;++i){
        cin>>tmp;
        counter[tmp]++;
    }
    for(int i=0;i<10001;++i){
        for(int j=0;j<counter[i];++j)
            cout<<i<<'\n';
    }
}
