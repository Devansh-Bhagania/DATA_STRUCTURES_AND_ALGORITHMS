// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL){
//             return root;
//         }
//         if(root->val>p->val && root->val>q->val){
//             return lowestCommonAncestor(root->left, p, q);
//         }
//         if(root->val<p->val && root->val<q->val){
//             return lowestCommonAncestor(root->right, p, q);
//         }
//         return root;
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


Node* lca(Node* root, Node* p , Node* q){
    if( root== NULL)return NULL;

    int curr = root->data;

    if(curr < p->data && curr < q->data){
        return lca(root->right, p, q);
    }
    if(curr > p->data && curr > q->data){
        return lca(root->left, p ,q);
    }

    return root;
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

     cout << "Enter the values of the two nodes to find their Lowest Common Ancestor:" << endl;
    int node1_val, node2_val;
    cin >> node1_val >> node2_val;

    Node* node1 = new Node(node1_val);
    Node* node2 = new Node(node2_val);

    Node* lowestCommonAncestor = lca(root, node1, node2);
    cout << "Lowest Common Ancestor of " << node1_val << " and " << node2_val << " is: " << lowestCommonAncestor->data << endl;

    preorder(root);  

    preorder(root); 
    return 0;
}