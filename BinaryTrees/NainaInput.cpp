#include<iostream>
#include<stdio.h>
using namespace std;


class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        right=left=NULL;
    }
};
void insert(Node* &root)
{
    int num;
    cout<<"enter number";
    cin>>num;
    if(num==-1){
        return;
    }
    if(root==NULL){
        root=new Node(num);
    }
    insert(root->left);
    insert(root->right);
}
int main(){
    Node* root=NULL;
    insert(root);
    cout<<root->data;
    cout<<root->left->data;
}