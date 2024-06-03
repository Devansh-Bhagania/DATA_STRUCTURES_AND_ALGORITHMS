#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Count the number of 0s, 1s, and 2s
        int count[3] = {0, 0, 0};
        ListNode* current = head;
        while (current) {
            count[current->val]++;
            current = current->next;
        }

        // Reconstruct the list based on the counts
        current = head;
        int index = 0;
        while (current) {
            if (count[index] == 0) {
                ++index;
            } else {
                current->val = index;
                --count[index];
                current = current->next;
            }
        }

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
    std::vector<int> arr = {2, 1, 0, 1, 2, 0, 1};
    ListNode* head = createLinkedList(arr);
    
    std::cout << "Original list:" << std::endl;
    printLinkedList(head);

    Solution solution;
    ListNode* sorted_head = solution.sortList(head);
    
    std::cout << "Sorted list:" << std::endl;
    printLinkedList(sorted_head);

    return 0;
}
