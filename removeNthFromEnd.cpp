#include <ListNode.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        { 
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};