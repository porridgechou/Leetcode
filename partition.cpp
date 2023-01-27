#include <ListNode.h>

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* p1 = dummy1;
        ListNode* p2 = dummy2;
        while (head != nullptr)
        {
            if (head->val < x) {
                p1->next = head;
                head = head->next;
                p1 = p1->next;
            }else {
                p2->next = head;
                head = head->next;
                p2 = p2->next;
            }
            // ListNode* temp = head->next;
            // head->next = nullptr;
            // head = temp;
        }
        p1->next = dummy2->next;
        p2->next = nullptr;
        return dummy1->next;
    }
};