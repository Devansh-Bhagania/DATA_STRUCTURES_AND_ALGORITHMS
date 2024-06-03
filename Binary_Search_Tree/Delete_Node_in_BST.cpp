// class Solution {
// public:

// TreeNode* deleteNode(TreeNode* root, int key) {
//         if( !root ) return NULL;
//         if( root->val < key ) root->right = deleteNode(root->right, key);
//         else if( root->val > key ) root->left = deleteNode(root->left, key);
//         else{
//             if( !root->right && !root->left ) return NULL;
//             else if( !root->right ) return root->left;
//             else if( !root->left ) return root->right;
//             else{
//                 TreeNode* temp = root->right;
//                 while( temp->left ) temp = temp->left;
//                 temp->left = root->left;
//                 return root->right;
//             }
//         }
//         return root;

//     }
// };

#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};


node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
      return root;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    node *temp = root;

    while (true)
    {
        if (temp->data <= val)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new node(val);
                break;
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new node(val);
                break;
            }
        }
    }
    return root;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

node *buildtree(node *root)
{
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = NULL;

    // root = buildtree(root);
    while (true)
    {
        int data;
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = insertNode(root, data);
    }

    cout << "Enter the value to delete from the BST: ";
    int key;
    cin >> key;

    root = deleteNode(root, 7);

    // cout << "BST in preorder traversal after inserting 8:" << endl;
    // root = insertNode(root, 8);

    preorder(root);
}