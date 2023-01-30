#include <al_zzh.h>

using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* preA = list1;
        ListNode* afterB = list1;
        for (int i = 0; i < a - 1; i++){ 
            preA = preA->next;
        }
        for (int i = 0; i < b + 1; i++) {
            afterB = afterB->next;
        }
        preA->next = list2;
        ListNode* tail = list2;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = afterB;
        return list1;
    }
};