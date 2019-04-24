#include<bits/stdc++.h>
using namespace std;
long long dp[31][31]={0,};                  //halfCnt, wholeCnt의 각각의 경우를 저장해둠


long long pill(int halfCnt,int wholeCnt){

    if( !(halfCnt+wholeCnt) )                 //둘다 0인 경우 문자열이 다 만들어 짐
        return 1;

    if(dp[halfCnt][wholeCnt])               //dp 확인
        return dp[halfCnt][wholeCnt];       //어차피 남은 경우( 반개의 개수, 한개의 개수) 가 같을 경우에는 같은 문자열이 만들어짐.

    long long sum=0;
    if(wholeCnt)
        sum += pill(halfCnt+1,wholeCnt-1);
    else                                    //남은 알약이 전부 반개인 경우 == 1 (HHHHH.....)
        return 1;

    if(halfCnt)
        sum +=pill(halfCnt-1,wholeCnt);

    dp[halfCnt][wholeCnt]=sum;
    return sum;
}



int main(){
    int N;
    for(int i=0;i<=30;++i){                 //30개 미리 계산
        dp[0][i]=pill(0,i);
    }
    cin>>N;
    while(N){
        cout<<dp[0][N]<<endl;
        cin>>N;
    }
}
