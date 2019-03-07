#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c,d;
    long long A=0,B=0,C=1;
    cin>>a>>b>>c>>d;
    for(int i=0;i<b.size();++i)
        a+=b[i];
    for(int i=0;i<d.size();++i)
        c+=d[i];
    C=1;
    for(int i=a.size()-1;i>=0;--i){
        A+=(a[i]-'0')*(C);
        C*=10;
    }
    C=1;
    for(int i=c.size()-1;i>=0;--i){
        B+=(c[i]-'0')*(C);
        C*=10;
    }
    cout<<A+B;
}
