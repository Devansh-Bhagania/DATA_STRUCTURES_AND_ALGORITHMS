// class Solution {
// public:
//     bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal){
//         if(root==NULL){
//             return true;
//         }
//         //1. root node's value should lie in its range
//         if(root->val<=minVal || root->val>=maxVal){
//             return false;
//         }
//         //2. & 3. left and right subtrees should be BST
//         return isValidBSTHelper(root->left, minVal, root->val) //left subtree
//         && isValidBSTHelper(root->right, root->val, maxVal); //right subtree
//     }
//     bool isValidBST(TreeNode* root) {
//         return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
//     }
// };

#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val <= root->data) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

bool isvalidbst(Node* root , long minval, long maxval){
    if(root == nullptr) return true;

    if(root->data >= maxval || root->data <=minval) return false;

    return isvalidbst(root->left, minval , root->data) && isvalidbst(root->right , root->data, maxval);
}

bool isValidBST(Node* root){
    return isvalidbst(root, LONG_MIN, LONG_MAX);
}

int main() {
    Node* root = nullptr;

    cout << "Enter the values to build the BST (end with -1):" << endl;
    while (true) {
        int data;
        cin >> data;
        if (data == -1) break;
        root = insertNode(root, data);
    }

    cout << "Is the binary tree a valid BST? " << (isValidBST(root) ? "Yes" : "No") << endl;

    preorder(root); 
    return 0;
}