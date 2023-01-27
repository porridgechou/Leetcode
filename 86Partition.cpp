#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Partition
{
private:
    /* data */
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallNode = new ListNode(0);
        ListNode* smallHead = smallNode;
        ListNode* largeNode = new ListNode(0);
        ListNode* largeHead = largeNode;
        while (head != nullptr)
        {
            if(head->val <x) {
                smallNode->next = head;
                smallNode = smallNode->next;
            } else {
                largeNode->next = head;
                largeNode = largeNode->next;
            }
            head = head->next;
        }
        //合并
        largeNode->next = nullptr;
        smallNode->next = largeHead->next;
        return smallHead->next;
    }
};

