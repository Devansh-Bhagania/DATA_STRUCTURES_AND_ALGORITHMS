#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};

// Merge two sorted linked lists
Node* merge(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->data < list2->data) {
        list1->child = merge(list1->child, list2);
        return list1;
    } else {
        list2->child = merge(list1, list2->child);
        return list2;
    }
}

// Flatten the linked list
Node* flattenLinkedList(Node* head) {
    if (!head || !head->next) return head;
    head->next = flattenLinkedList(head->next);
    return merge(head, head->next);
}

// Print the flattened linked list
void printLinkedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->child = new Node(14);
    head->next = new Node(10);
    head->next->child = new Node(4);
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    Node* flattened = flattenLinkedList(head);
    cout << "Flattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
