class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal){
        if(root==NULL){
            return true;
        }
        //1. root node's value should lie in its range
        if(root->val<=minVal || root->val>=maxVal){
            return false;
        }
        //2. & 3. left and right subtrees should be BST
        return isValidBSTHelper(root->left, minVal, root->val) //left subtree
        && isValidBSTHelper(root->right, root->val, maxVal); //right subtree
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};