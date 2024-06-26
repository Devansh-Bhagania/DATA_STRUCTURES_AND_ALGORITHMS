class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode* d1 = headA;
    ListNode* d2 = headB;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headA:d1->next;
        d2 = d2 == NULL? headB:d2->next;
    }
    
    return d1;
    }
};