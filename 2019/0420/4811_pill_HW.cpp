#include<bits/stdc++.h>
using namespace std;
long long dp[31][31]={0,};                  //halfCnt, wholeCnt�� ������ ��츦 �����ص�


long long pill(int halfCnt,int wholeCnt){

    if( !(halfCnt+wholeCnt) )                 //�Ѵ� 0�� ��� ���ڿ��� �� ����� ��
        return 1;

    if(dp[halfCnt][wholeCnt])               //dp Ȯ��
        return dp[halfCnt][wholeCnt];       //������ ���� ���( �ݰ��� ����, �Ѱ��� ����) �� ���� ��쿡�� ���� ���ڿ��� �������.

    long long sum=0;
    if(wholeCnt)
        sum += pill(halfCnt+1,wholeCnt-1);
    else                                    //���� �˾��� ���� �ݰ��� ��� == 1 (HHHHH.....)
        return 1;

    if(halfCnt)
        sum +=pill(halfCnt-1,wholeCnt);

    dp[halfCnt][wholeCnt]=sum;
    return sum;
}



int main(){
    int N;
    for(int i=0;i<=30;++i){                 //30�� �̸� ���
        dp[0][i]=pill(0,i);
    }
    cin>>N;
    while(N){
        cout<<dp[0][N]<<endl;
        cin>>N;
    }
}
