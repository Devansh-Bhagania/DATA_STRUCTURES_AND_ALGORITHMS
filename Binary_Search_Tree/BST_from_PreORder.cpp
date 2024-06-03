 #include<iostream>
 #include<climits>
 #include<vector>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left=right=NULL;
    }
};

Node* build(vector<int> &A, int &i, int bound){
    if(i==A.size() || A[i] > bound) return NULL;

    Node* root = new Node(A[i++]);

    root->left = build(A, i, root->data);
    root->right = build(A, i ,bound);
    return root;
};


Node* constructBSTFromPreorder(vector<int> &A){
    int i =0 ;
    return build(A, i , INT_MAX);
};

void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
};

int main(){
    vector<int> A = {10, 5, 1, 8, 15};

    Node* root = constructBSTFromPreorder(A);

     cout << "Inorder traversal of constructed BST: ";
    printInOrder(root);
    cout << endl;

    return 0;

}           