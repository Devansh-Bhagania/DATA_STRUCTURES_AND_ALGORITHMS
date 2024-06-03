#include<iostream>
using namespace std;


class node {
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left=right=NULL;
    }
};


node* searchbst(node* root, int val){
    while(root != NULL && root->val != val){
        root = val<root->val ? root->left : root->right;
    }
    return root;
}


node* buildtree(node* root){

    cout<<"enter data"<<" ";
    int data;
    cin >> data;

    root = new node(data);

    if(data==-1){
        return NULL;
    } 

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

int main(){
    node* root = NULL;

    root = buildtree(root);



    root = searchbst(root,5);
    
}