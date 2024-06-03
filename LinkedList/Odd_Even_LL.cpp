#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = even_head;
        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    
    std::cout << "Original list:" << std::endl;
    printLinkedList(head);

    Solution solution;
    ListNode* new_head = solution.oddEvenList(head);
    
    std::cout << "After rearranging:" << std::endl;
    printLinkedList(new_head);

    return 0;
}
