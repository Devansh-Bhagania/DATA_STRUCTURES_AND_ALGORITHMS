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

class Solution {
private:
    void reverseInorder(Node* root, int& counter, int k, int& kthLargest) {
        if (!root || counter >= k) return;
        reverseInorder(root->right, counter, k, kthLargest);
        if (++counter == k) {
            kthLargest = root->data;
            return;
        }
        reverseInorder(root->left, counter, k, kthLargest);
    }

    void inorder(Node* root, int& counter, int k, int& kthSmallest) {
        if (!root || counter >= k) return;
        inorder(root->left, counter, k, kthSmallest);
        if (++counter == k) {
            kthSmallest = root->data;
            return;
        }
        inorder(root->right, counter, k, kthSmallest);
    }

public:
    pair<int, int> findKth(Node* root, int k) {
        int kthSmallest = INT_MIN, kthLargest = INT_MIN, counter = 0;
        inorder(root, counter, k, kthSmallest);
        counter = 0;
        reverseInorder(root, counter, k, kthLargest);
        return {kthSmallest, kthLargest};
    }
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

int main() {
    Node* root = nullptr;

    cout << "Enter the values to build the BST (end with -1):" << endl;
    while (true) {
        int data;
        cin >> data;
        if (data == -1) break;
        root = insertNode(root, data);
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    auto result = solution.findKth(root, k);
    cout << "The " << k << "-th smallest element is: " << result.first << endl;
    cout << "The " << k << "-th largest element is: " << result.second << endl;

    preorder(root); // Moved this line after the output
    return 0;
}
