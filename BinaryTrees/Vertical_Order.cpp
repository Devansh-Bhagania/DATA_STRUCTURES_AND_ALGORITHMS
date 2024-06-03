#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    map<int, vector<int>> verticalOrder;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto node = q.front().first;
            int hd = q.front().second;
            q.pop();
            verticalOrder[hd].push_back(node->val);
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
    }

    for (const auto& entry : verticalOrder) {
        result.push_back(entry.second);
    }

    return result;
}

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Construct the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Perform vertical order traversal
    vector<vector<int>> verticalOrder = verticalTraversal(root);

    // Print the result
    cout << "Vertical Order Traversal:" << endl;
    for (const auto& level : verticalOrder) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
