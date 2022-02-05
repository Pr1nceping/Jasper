/**
 * This file defined a sort of incomplete functions about linked list.
 * You need to complete these functions to make all the test cases passed.
 */
#include "Solution.h"
ListNode* Solution::BuildFromXToY(int X, int Y) {
    //TODO: Task 2 Please insert your code here
    ListNode* head;
    ListNode* newnode=nullptr;
    ListNode* temp;
    if(Y>=X) {
        head = new ListNode;
        head->value = X;
        head->next = nullptr;
        temp = head;
        if (X != Y) {
            for (int i = X; i < Y; i++) {
                newnode = new ListNode;
                newnode->value = i + 1;
                temp->next = newnode;
                temp = temp->next;
            }
            newnode->next = nullptr;
        }
        return head;
    }
    else{
         return nullptr;
    }
}
int Solution::CountLength(ListNode *head) {
    //TODO: Task 3 Please insert your code here
    int length =0;
    ListNode* current = head; //
    while(current!=nullptr){
        length = length + 1;
        current=current->next;
    }
    return length;
}

ListNode* Solution::AddNode(ListNode *head, int newValue) {
    //TODO: Task 4 Please insert your code here
    ListNode* newnode=nullptr;
    ListNode* current = head;
    ListNode* temp;
    if(newValue<current->value){
        newnode = new ListNode;
        newnode->value=newValue;
        newnode->next=current;
        current = newnode;
    }
    else if(newValue>current->value){
        for(int i = current->value;newValue>i;i++){
            temp->value=i;
            current=current->next;
        }
        newnode = new ListNode;
        newnode->value=newValue;
        newnode->next=current->next;
        temp->next=newnode;
    }
    return current;
}

ListNode* Solution::DeleteNode(ListNode *head, int targetValue) {
    //TODO: Task 5 Please insert your code here

}
