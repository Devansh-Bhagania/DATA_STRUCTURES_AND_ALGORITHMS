                            
// #include <iostream>
// #include <vector>
// #include <climits> 
// using namespace std;

// // Definition of TreeNode structure
// // for a binary tree node
// struct TreeNode {
//     // Value of the node
//     int val;
    
//     // Pointer to the left child node
//     TreeNode* left;
    
//     // Pointer to the right child node
//     TreeNode* right;

//     // Constructor to initialize the node with a
//     // value and set left and right pointers to null
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     // Function to find the ceiling of
//     // a key in a Binary Search Tree (BST)
//     int findCeil(TreeNode* root, int key){
//         // Initialize the variable
//         // to store the ceiling value
//         int ceil = -1; 
        
//         // Traverse the BST until reaching
//         // the end or finding the key
//         while(root){
//              // If the key is found, assign it
//              // as the ceiling and return
//             if(root->val == key){
//                 ceil = root->val;
//                 return ceil;
//             } 
            
//              // If the key is greater,
//              // move to the right subtree
//             if(key > root->val){
//                 root = root->right;
//             }
//             else{ 
//                 // If the key is smaller, update ceil
//                 // and move to the left subtree
//                 ceil = root->val;
//                 root = root->left;
//             }
//         }
//          // Return the computed ceiling value
//         return ceil;
//     }
// };


// // Function to perform an in-order traversal
// // of a binary tree and print its nodes
// void printInOrder(TreeNode* root) {
//     // Check if the current node
//     // is null (base case for recursion)
//     if (root == nullptr) {
//         // If null, return and
//         // terminate the function
//         return;
//     }

//     // Recursively call printInOrder
//     // for the left subtree
//     printInOrder(root->left);

//     // Print the value of the current node
//     cout << root->val << " ";

//     // Recursively call printInOrder
//     // for the right subtree
//     printInOrder(root->right);
// }

// int main() {
//     // Creating a BST
//     TreeNode* root = new TreeNode(10);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(13);
//     root->left->left = new TreeNode(3);
//     root->left->left->left = new TreeNode(2);
//     root->left->left->right = new TreeNode(4);
//     root->left->right = new TreeNode(6);
//     root->left->right->right = new TreeNode(9);
//     root->right->left = new TreeNode(11);
//     root->right->right = new TreeNode(14);
    
//     cout << "Binary Search Tree: "<< endl;
//     printInOrder(root);
//     cout << endl;

//     Solution solution;
    
//     // Searching for a value in the BST
//     int target = 8;
//     int ciel = solution.findCeil(root, target);
    
//     if(ciel != -1){
//         cout << "Ceiling of " << target << " is: " << ciel << endl;
//     }
//     else{
//         cout << "No ceiling found!";
//     }
    
//     return 0;
// }
                            
                        


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



int ceil(node* root, int key){
    int ceil = -1;
    
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(root->data < key){
            root = root->right;
        }

        else{
            ceil = root->data;
            root = root->left;

        }
    }
    return ceil;
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


int main(){
    node* root = NULL;

    root = buildtree(root);

    int ans = ceil(root,8);

    cout<<ans;
}