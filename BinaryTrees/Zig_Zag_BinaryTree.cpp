// class Solution
// {
// public:
//     vector<vector<int>> ZigZagLevelOrder(Node *root)
//     {

//         vector<vector<int>> result;

//         if (root == NULL)
//         {
//             return result;
//         }

//         queue<Node *> nodesQueue;
//         nodesQueue.push(root);

//         bool leftToRight = true;
        
//         while (!nodesQueue.empty())
//         {
//             int size = nodesQueue.size();
//             vector<int> row(size);
//             for (int i = 0; i < size; i++)
//             {
//                 Node *node = nodesQueue.front();
//                 nodesQueue.pop();
//                 int index = leftToRight ? i : (size - 1 - i);
//                 row[index] = node->data;
//                 if (node->left)
//                 {
//                     nodesQueue.push(node->left);
//                 }
//                 if (node->right)
//                 {
//                     nodesQueue.push(node->right);
//                 }
//             }

//             leftToRight = !leftToRight;
//             result.push_back(row);
//         }

//         return result;
//     }
// };


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left=right=NULL;
    }
};



vector<vector<int>> zigzagtraversal(node* root){
    vector<vector<int>> result;

    queue<node*> q;
    q.push(root);


    bool lefttoRight = true;

    while(!q.empty()){
        
        int size = q.size();
        vector<int> row(size);



        for(int i=0;i<size;i++){
            node* temp = q.front();
            q.pop();

            int index = lefttoRight ? i : size -1 -i;


            row[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }

             if(temp->right){
                q.push(temp->right);
            }

        }


        lefttoRight = !lefttoRight;

        result.push_back(row);

    }

    return result;

    
}


node* buildtree(node* root){

    cout<<"enter data"<<' ';
    int data;
    cin>> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    root->left = buildtree(root->left);
    root->right = buildtree(root->right);

    return root;
}

int main(){

    node* root = NULL;

    root = buildtree(root);

    zigzagtraversal(root);
}