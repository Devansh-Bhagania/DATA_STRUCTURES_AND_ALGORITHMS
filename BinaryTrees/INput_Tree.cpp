
#include <bits/stdc++.h>
using namespace std;


// started JWT 
 
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTree(vector<int> &nums){
            if(nums.empty){
                return NULL;
            }

            TreeNode* root = new TreeNode(nums[0]);

            queue<TreeNode*> q;

            q.push(root);
            int i = 1;

            while(i<nums.size()){
                TreeNode* curr = q.front();

                q.pop();

                if(i<nums.size()){
                    curr->left = new TreeNode(nums[i++]);
                    q.push(curr->left);
                }

                if(i<nums.size()){
                    curr->right = new TreeNode(nums[i++]);
                    q.push(curr->right);
                }
            }
        return root;
}
 


 int main(){
        vector<int> nums = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
        TreeNode* root = buildTree(nums);
        printTree(root);
        return 0;
 }