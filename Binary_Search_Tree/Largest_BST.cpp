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
};

void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
};


struct Bstinfo{
    bool isBST;
    int size;
    Node* root;


    Bstinfo(bool isBST, int size , Node* root)
    : isBST(isBST), size(size), root(root) {}
};


Bstinfo findlargestBST(Node* root, int &maxsize){
    if( root == NULL) return {true, 0 , nullptr};


    auto left = findlargestBST(root->left,maxsize);
    auto right = findlargestBST(root->right,maxsize);

    if(left.isBST && right.isBST || (!root->left || root->data > left.root->data) && (!root->right || root->data < right.root->data)){
        int size = 1 + left.size + right.size;
        if(size > maxsize) maxsize  = size;

        return {true, size ,root};
    } 

    return {false ,0, nullptr};
}


int main(){
     Node* root = nullptr;

    cout << "Enter the values to build the BST (end with -1):" << endl;
    while (true) {
        int data;
        cin >> data;
        if (data == -1) break;
        root = insertNode(root, data);
    }

      int maxSize = 0;
    findlargestBST(root, maxSize);

    cout << "Nodes of the largest BST: ";
    printInOrder(root);
    cout << endl;




   
}