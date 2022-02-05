/**
 * This file defined 3 constructors of the ListNode class.
 * You need to complete the constructors here so that all the pre-defined test cases can be passed successfully.
 */


#include "ListNode.h"

ListNode::ListNode() {
    //TODO: Task 1 Please insert your code here
        value=0;
        next=nullptr;
}

ListNode::ListNode(int initialValue) {
    //TODO: Task 1 Please insert your code here
        value = initialValue;
        next = nullptr;
}

ListNode::ListNode(int initialValue, ListNode* nextNode) {
    //TODO: Task 1 Please insert your code here
        value = initialValue;
        next = nextNode;
}
