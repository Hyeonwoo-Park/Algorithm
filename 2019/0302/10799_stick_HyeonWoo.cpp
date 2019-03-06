#include<bits/stdc++.h>
using namespace std;

int main(){
    string input;
    stack<char> bracket;
    int sum=0;
    cin>>input;
    for(int i=0;i<input.size();++i){
        if(input[i] == '('){
            bracket.push(input[i]);
            continue;
        }
        else{
            if(input[i-1]=='('){
                bracket.pop();
                sum+=bracket.size();
                continue;
            }
            else{
                bracket.pop();
                sum++;
                continue;
            }
        }
    }
    cout<<sum;
}
