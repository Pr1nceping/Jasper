/**
 * This file defined a sort of incomplete functions about linked list.
 * You need to complete these functions to make all the test cases passed.
 */

#include "Solution.h"



ListNode* Solution::BuildFromXToY(int X, int Y) {
    //TODO: Task 2 Please insert your code here
    ListNode* head;
    ListNode* tail;
    ListNode* newnode;
    ListNode* temp;
    if(Y>X) {
        head = new ListNode;
        head->value = X;
        tail->value = Y;

        for (int i = X; i <= tail->value; i++) {
            newnode = new ListNode;
            newnode->next->value=X+i;
            temp->next=newnode;
            temp=temp->next;
        }
        newnode->next = nullptr;
    }
    else{
         return nullptr;
    }
}

int Solution::CountLength(ListNode *head) {
    //TODO: Task 3 Please insert your code here
    return -1;
}

ListNode* Solution::AddNode(ListNode *head, int newValue) {
    //TODO: Task 4 Please insert your code here
    return head;
}

ListNode* Solution::DeleteNode(ListNode *head, int targetValue) {
    //TODO: Task 5 Please insert your code here
    return head;
}
