#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node * child[10];
    int chk[10] = {0,};
    int word = 0;
    bool end_=false;
};

int append(Node * node, string num){
    if(node->end_){
        return 1;
    }
    if(num.size() == 0){
        node->end_=true;
        if(node->word == 1 )
            return 1;
        node->word =1;
        return 0;
    }
    node->word =1;
    int child = num[0]-'0';
    num.erase(0,1);
    if(node->chk[child]==0){
        node->child[child] = new Node();
        node->chk[child] = 1;
    }
    return append(node->child[child],num);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        Node root;
        int N,i;
        cin>>N;
        string num;
        bool flag = true;
        for(i=0;i<N;++i){
            cin>>num;
            if(append(&root,num) && flag){
                cout<<"NO"<<endl;
                flag=false;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
    return 0;
}
