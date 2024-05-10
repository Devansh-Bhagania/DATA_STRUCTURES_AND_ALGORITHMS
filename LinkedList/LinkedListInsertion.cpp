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


// insert at head -------------------

Node* insertAtHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}


Node* insertAtTail(Node* head, int val){
    if (head== NULL) return new Node(val);
    Node* rte = new Node(val);
    Node* temp = head;
  
        while(temp->next != NULL){
             temp = temp->next;
        };
        temp->next = rte;
      return head;
}

Node* insertAtK(Node* head, int el,int val){
        if(head == NULL){
           return head;
        }
        if(head->data == val){
            return new Node(el);
        }

        Node* temp = head;
        while(temp->next != NULL){
     
                if(temp->next->data == val){
                    Node* fe = new Node(el);
                    fe->next = temp->next;
                    temp->next = fe;
                    break;
                }
                temp = temp->next;
        }
        return head;

}


// Node* insertBeforeValue(Node* head, int el, )



 ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextNode = head;

        while(current){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
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
    // head = removel(head,5);
    // head = removeTail(head);

    // head =  insertAtTail(head,45);

    head = insertAtK(head, 56, 2);
    print(head);
}
