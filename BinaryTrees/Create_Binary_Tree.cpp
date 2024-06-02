// #include<iostream>
// #include<queue>
// using namespace std;

// class node {
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int d){
//         data = d;
//         left=right=NULL;
//     }
// };

// node* buildtree(node* root){

//     cout<<"Enter the data: "<< endl;
//     int data;
//     cin >> data;
    
//     root = new node(data);


//     if(data == -1){
//         return NULL;
//     }

//     cout<<"Enter data for left"<<endl;
//     root->left = buildtree(root->left);

//     cout<<"Enter data for right"<<endl;
//     root->right = buildtree(root->right);
    
//     return root;
// }

// void levelOrderTraversal(node* root){
//         queue<node*> q;
//         q.push(root);

//         while(!q.empty()){
//             node* temp = q.front();
//             cout<< temp->data  << ' ';
//             q.pop();

//             if(temp->left){
//                 q.push(temp->left);
//             }

//             if(temp->right){
//                 q.push(temp->right);
//             }
//         }
// }

// int main(){

//     node* root = NULL;

//     root = buildtree(root);

//     levelOrderTraversal(root);

//     return 0;
// }


#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data ;
    node* left;
    node* right;

    node(int d){
        data=d;
        right=left=NULL;
    }
};


node* buildtree(node* root){

    cout<<"enter data"<< " ";
    int data ;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"enter data for left"<<" ";
    root->left = buildtree(root->left);

    cout<<"enter data for right"<<" ";
    root->right = buildtree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<' ';
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}



void preorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = NULL;

    root = buildtree(root);


    levelOrderTraversal(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);


    return 0;
}