#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    std::vector<std::pair<int, int>> findPairsWithSum(ListNode* head, int sum) {
        std::vector<std::pair<int, int>> result;
        ListNode* current1 = head;

        // Check each pair of nodes
        while (current1) {
            ListNode* current2 = current1->next;
            while (current2) {
                if (current1->val + current2->val == sum) {
                    result.push_back({current1->val, current2->val});
                }
                current2 = current2->next;
            }
            current1 = current1->next;
        }

        return result;
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
    std::vector<int> arr = {1, 5, 7, -1, 5};
    int target_sum = 6;
    ListNode* head = createLinkedList(arr);
    
    std::cout << "Original list:" << std::endl;
    printLinkedList(head);

    Solution solution;
    std::vector<std::pair<int, int>> pairs = solution.findPairsWithSum(head, target_sum);

    std::cout << "Pairs with sum " << target_sum << ":" << std::endl;
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    return 0;
}

