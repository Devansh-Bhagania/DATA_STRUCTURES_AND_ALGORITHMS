#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data2){
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};


Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev  = NULL;
    Node* current = head ;
    while(current != NULL){
        prev = current->prev;
        current->prev = current->next;
        current->next= prev;

        current = current-> prev;
    }
    return prev->prev;
}


Node* convertArr2Dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


// delete head ========================================

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev= head;
    head = head->next;

    head->back= nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

// delete tail ============================ 

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail =  head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next= nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node removeKthElement(Node* head,int k){
    if(head == NULL){
        return NULL;
    }

    int cnt = 0;
    Node* kNode = head;

    while(kNode != NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front =kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}


void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2Dll(arr);
    print(head);
    head = deleteHead(head);
    print(head);
    return 0;
}


