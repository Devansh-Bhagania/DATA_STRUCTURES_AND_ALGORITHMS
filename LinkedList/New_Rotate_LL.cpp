#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }
        current->next = head; // Make it circular

        k = length - k % length;
        while (k--) current = current->next;

        head = current->next;
        current->next = nullptr;
        return head;
    }
};

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

void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    ListNode* head = createLinkedList(arr);
    
    std::cout << "Original list:\n";
    printLinkedList(head);

    Solution solution;
    ListNode* rotatedHead = solution.rotateRight(head, k);

    std::cout << "Rotated list by " << k << " places:\n";
    printLinkedList(rotatedHead);

    return 0;
}
