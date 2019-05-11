#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int x=0;
    vector<string> save;
    vector<string> save_ps;
    for(int i=0;i<N;++i){
        save_ps.assign(save.begin(),save.end());
        save.clear();


        x=x*2+1;
        int vec_tmp=0;
        for(int j=0;j<x;++j){
            string tmp = "";
            if(i%2 ==0){
                for(int k=j;k<x-1;++k){
                    tmp+=' ';
                }
                int foo=0;
                for(int k=0;k<(j+1)*2-1;++k){
                    if( j>= x/2 && j< x-1  && k >= vec_tmp+1 && k< vec_tmp+ x/2 + x/2  ){
                        if(foo <save_ps[vec_tmp].size())
                            tmp+=save_ps[vec_tmp][foo];
                        else
                            tmp+=' ';
                        foo++;
                    }
                    else if(k==0 || k == (j+1)*2-2 || j == x-1)
                        tmp+='*';
                    else
                        tmp+=' ';
                }
                if(j>= x/2 && j< x-1)
                    vec_tmp++;
            }
            else{
                for(int k=x-j-1;k<x-1;++k){
                    tmp+=' ';
                }
                int foo=0;
                for(int k=0;k<(x-j-1)*2+1;k++){
                    if(j>=1 && j<= x/2 &&  k>(x+1)/2-vec_tmp-2 && k< (x+1)/2-vec_tmp+ x/2 + x/2-2  ){
                        if(foo <save_ps[vec_tmp].size())
                            tmp+=save_ps[vec_tmp][foo];
                        else
                            tmp+=' ';
                        foo++;
                    }
                    else if(k==(x-j-1)*2 || k == 0 || j == 0)
                        tmp+='*';
                    else
                        tmp+=' ';
                }
                if(j>=1 && j<= x/2)
                    vec_tmp++;
            }
            save.push_back(tmp);
        }
    }
    for(int j=0;j<save.size();++j){
        cout<<save[j]<<endl;
    }
}
