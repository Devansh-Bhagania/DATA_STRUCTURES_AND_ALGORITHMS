#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* converArrToLL(vector<int>  &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int length(Node* head){
    int count = 0 ;
     Node* temp = head;
    while(temp){
        // cout<<temp->data<<' ';
        temp=temp->next;
        count++;
    }
    return count;
}

int checkIfElementPresent(Node* head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}


void print(Node* head){
    while(head != NULL){
        cout << head->data<<' ';
        head = head->next;
    }
    cout<<endl;
}

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
        if( head == NULL || head->next == NULL) return NULL;
        Node* temp = head;

        while(temp->next->next == NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next = nullptr;

        return head;

}

Node* removeK(Node* head,int k){
    if(head == NULL) return head;

    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// remove element by data ------------------------------
Node* removel(Node* head,int el){
    if(head == NULL) return head;

    if(head->data==el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // int count =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        
        if(temp->data== el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    // Node* y = new Node(arr[0],nullptr);
    Node* head = converArrToLL(arr);
    Node* temp = head;

    while(temp){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    // cout<<y->data;
    cout<<length(head);
    // cout<< checkIfElementPresent(head,13);
    // head = removesHead(head);
    print(head);
    // head = removeK(head,3);
    head = removel(head,5);
    // head = removeTail(head);
    print(head);
}
