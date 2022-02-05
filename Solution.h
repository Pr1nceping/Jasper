#include "ListNode.h"


class Solution {
public:
    static ListNode* BuildFromXToY(int X, int Y);
    static int CountLength(ListNode* head);
    static ListNode* AddNode(ListNode *head, int newValue);
    static ListNode* DeleteNode(ListNode *head, int targetValue);
};

class Helper {
public:
    /*
     * Concatenate 2 linked list together.
     * e.g, 1->2->3 + 7->8 => 1->2->3->7->8
     */
    static ListNode* Concatenate(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)
        {
            return nullptr;
        }

        ListNode* p = l1;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = l2;
        return l1;
    }
};
