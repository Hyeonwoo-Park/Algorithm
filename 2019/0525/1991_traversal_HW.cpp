#include<bits/stdc++.h>
using namespace std;
struct Node{
    char name;
    Node* leftNode=nullptr;
    Node* rightNode=nullptr;
};
void searching(Node * node, char p, char lc, char rc){
    if(node->name == p){
        if(lc!='.'){
            if(node->leftNode == nullptr)
                node->leftNode = new Node();
            node->leftNode->name = lc;
        }

        if(rc!='.'){
            if(node->rightNode == nullptr)
                node->rightNode = new Node();
            node->rightNode->name = rc;
        }

    }
    else{
        if(node->leftNode != nullptr)
            searching(node->leftNode,p,lc,rc);
        if(node->rightNode != nullptr)
            searching(node->rightNode,p,lc,rc);
    }
}
void preorder (Node *node){
    cout<<node->name;
    if(node->leftNode != nullptr)
        preorder(node->leftNode);
    if(node->rightNode != nullptr)
        preorder(node->rightNode);
}
void inorder(Node *node){
    if(node->leftNode != nullptr)
        inorder(node->leftNode);
    cout<<node->name;
    if(node->rightNode != nullptr)
        inorder(node->rightNode);
}
void postorder (Node *node){
    if(node->leftNode != nullptr)
        postorder(node->leftNode);
    if(node->rightNode != nullptr)
        postorder(node->rightNode);
    cout<<node->name;
}


int main(){
    Node * root =new Node();
    root->name = 'A';
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        char a,b,c;
        cin>>a>>b>>c;
        searching(root,a,b,c);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
