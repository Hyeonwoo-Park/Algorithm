#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int l,n;
        cin>>l>>n;
        int min_=0;
        int max_=0;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;

            if( tmp > l/2 ){
                if(l - tmp > min_){
                    min_=l-tmp;
                }
            }
            else{
                if( tmp > min_ )
                    min_=tmp;
            }

            if( (l-tmp) > max_ )
                max_ = ( l-tmp ) ;
            if ( tmp > max_ )
                max_ = tmp;
        }

        cout<<min_<<' '<<max_<<endl;
    }
}
