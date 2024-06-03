#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check the children sum property
bool isChildrenSumProperty(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return true;  // Base case: empty node or leaf node

    int leftVal = (root->left) ? root->left->val : 0;
    int rightVal = (root->right) ? root->right->val : 0;

    return (root->val == leftVal + rightVal) &&
           isChildrenSumProperty(root->left) &&
           isChildrenSumProperty(root->right);
}

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Construct the binary tree
    TreeNode* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);

    // Check if the tree satisfies children sum property
    if (isChildrenSumProperty(root))
        cout << "The tree satisfies the children sum property." << endl;
    else
        cout << "The tree does not satisfy the children sum property." << endl;

    return 0;
}
