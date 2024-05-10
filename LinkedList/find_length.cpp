
int findlength(Node* slow,Node*fast){
    int cnt = 1;
    fast = fast->next;

    while(slow!=fast){
        cnt++;
        fast= fast->next;
    }
    return cnt;
}







bool detectCycle(Node* head) {
    // Initialize two pointers, slow and fast,
    // to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Step 2: Traverse the linked list with
    // the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return findlength(slow,fast);  // Loop detected
        }
    }

    // If fast reaches the end of the list,
    // there is no loop
    return false;
}