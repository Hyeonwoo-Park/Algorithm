#include<bits/stdc++.h>
using namespace std;

int up(vector<vector<int>> &board,int x, int y){

}
int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;++i){
        int N;
        string op;
        cin>>N>>op;
        vector<vector<int>> board(N,vector<int>(N));
        for(int j=0;j<N;++j){
            for(int k=0;k<N;++k){
                cin>>board[j][k];
            }
        }
        if(op=="up"){
            for(int k=0;k<N;++k){
                for(int j=0;j<N-1;++j){
                    int tmp=0;
                    for(int l=j+1;l<N;++l){
                        if(board[l][k]!=0){
                            tmp=board[l][k];
                            board[l][k]=0;
                            break;
                        }
                    }
                    if(tmp!=0){
                        if(board[j][k]==0){
                            board[j][k]=tmp;
                            j--;
                        }
                        else if(tmp==board[j][k]){
                            board[j][k]*=2;
                        }
                        else
                            board[j+1][k]=tmp;
                    }
                }
            }
        }
        if(op=="left"){
            for(int j=0;j<N;++j){
                for(int k=0;k<N-1;++k){
                    int tmp=0;
                    for(int l=k+1;l<N;++l){
                        if(board[j][l]!=0){
                            tmp=board[j][l];
                            board[j][l]=0;
                            break;
                        }
                    }
                    if(tmp!=0){
                        if(board[j][k]==0){
                            board[j][k]=tmp;
                            k--;
                        }
                        else if(tmp==board[j][k]){
                            board[j][k]*=2;
                        }
                        else
                            board[j][k+1]=tmp;
                    }
                }
            }
        }
        if(op=="down"){
            for(int k=0;k<N;++k){
                for(int j=N-1;j>0;--j){
                    int tmp=0;
                    for(int l=j-1;l>=0;--l){
                        if(board[l][k]!=0){
                            tmp=board[l][k];
                            board[l][k]=0;
                            break;
                        }
                    }
                    if(tmp!=0){
                        if(board[j][k]==0){
                            board[j][k]=tmp;
                            j++;
                        }
                        else if(tmp==board[j][k]){
                            board[j][k]*=2;
                        }
                        else
                            board[j-1][k]=tmp;
                    }
                }
            }
        }
        if(op=="right"){
            for(int j=0;j<N;++j){
                for(int k=N-1;k>0;--k){
                    int tmp=0;
                    for(int l=k-1;l>=0;--l){
                        if(board[j][l]!=0){
                            tmp=board[j][l];
                            board[j][l]=0;
                            break;
                        }
                    }
                    if(tmp!=0){
                        if(board[j][k]==0){
                            board[j][k]=tmp;
                            k++;
                        }
                        else if(tmp==board[j][k]){
                            board[j][k]*=2;
                        }
                        else
                            board[j][k-1]=tmp;
                    }
                }
            }
        }
        cout<<'#'<<i<<'\n';
        for(int j=0;j<N;++j){
            for(int k=0;k<N;++k){
                cout<<board[j][k]<<' ';
            }
            cout<<endl;
        }
    }






}
