/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//             if(root == NULL) return new TreeNode(val);
//             TreeNode *cur  = root;
//             while(true){
//                 if(cur->val <= val){
//                     if(cur->right != NULL) cur = cur->right;
//                     else{
//                         cur->right = new TreeNode(val);
//                         break;
//                     }
//                 } else{
//                     if(cur->left != NULL) cur = cur->left;
//                     else{
//                         cur->left = new TreeNode(val);
//                         break;
//                     }
//                 }
//             }
//             return root;
//     }
// };


 #include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left=right=NULL;
    }
};



node* insertNode(node* root , int val){
    if(root == NULL){
        root = new node(val);
        return root;
    }

    node* temp = root;

    while(true){
        if(temp->data <= val){
            if(temp->right != NULL){
                temp = temp->right;
            }else{
                temp->right = new node(val);
                break;
            }
        }else{
            if(temp->left != NULL){
                temp = temp->left;
            }else{
                temp->left = new node(val);
                break;
            }
        }
        
    }
    return root;
}


node* buildtree(node* root){
    int data ;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}


void preorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root = NULL;

    // root = buildtree(root);
    while (true) {
        int data;
        cin >> data;
        if (data == -1) {
            break;
        }
        root = insertNode(root, data);
    }

     cout << "BST in preorder traversal after inserting 8:" << endl;
    root = insertNode(root, 8);

    preorder(root);
}                       