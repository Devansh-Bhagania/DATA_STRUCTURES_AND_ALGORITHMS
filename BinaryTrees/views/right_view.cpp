class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root,0,res);
        return res;
    }

    void recursion(TreeNode* root, int level, vector<int> & res){
        if(root==NULL) return ;
        if(res.size() == level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
};



vector<int> ans;
recursion (root,0,res);

if(root == NULL) return;

if(res.size() == level) res.push_back(node->val);

recusion(root->left, level+1,res)
recusion (root->right,level_1, res);