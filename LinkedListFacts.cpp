/**
 * This file defines a sort of test cases for linked list.
 *
 * You can read the code here getting some hints about what is required.
 *
 * But please do NOT change the code here.
 * You should implement the functions in "src/Solution.cpp" to pass all the tests.
 */

#include "gtest/gtest.h"
#include "Solution.h"


/* BuildFromXToY*/
TEST(TestForLinkedListBuild, should_build_a_linked_list_from_0_to_3) {
    // GIVEN
    int X = 0;
    int Y = 3;

    // WHEN
    ListNode* head = Solution::BuildFromXToY(X, Y);

    // THEN
    ASSERT_NE(nullptr, head);
    ASSERT_EQ(0, head->value);

    ASSERT_NE(nullptr, head->next);
    ASSERT_EQ(1, head->next->value);

    ASSERT_NE(nullptr, head->next->next);
    ASSERT_EQ(2, head->next->next->value);

    ASSERT_NE(nullptr, head->next->next->next);
    ASSERT_EQ(3, head->next->next->next->value);

    ASSERT_EQ(nullptr, head->next->next->next->next);
}

TEST(TestForLinkedListBuild, should_build_a_linked_list_with_single_node_when_X_equal_to_Y) {
    // GIVEN
    int X = 2303;
    int Y = 2303;

    // WHEN
    ListNode* head = Solution::BuildFromXToY(X, Y);

    // THEN
    ASSERT_NE(nullptr, head);
    ASSERT_EQ(2303, head->value);
    ASSERT_EQ(nullptr, head->next);
}

TEST(TestForLinkedListBuild, should_return_nullptr_when_Y_less_than_X) {
    // GIVEN
    int X = 2303;
    int Y = 2302;

    // WHEN
    ListNode* head = Solution::BuildFromXToY(X, Y);

    // THEN
    ASSERT_EQ(nullptr, head);
}

TEST(TestForLinkedListBuild, should_build_a_linked_list_from_neg_2000_to_303) {
    // GIVEN
    int X = -2000;
    int Y = 303;

    // WHEN
    ListNode* head = Solution::BuildFromXToY(X, Y);

    // THEN
    ASSERT_NE(nullptr, head);

    int count = X;
    ListNode* current = head;
    while(count <= Y)
    {
        ASSERT_NE(nullptr, current);
        ASSERT_EQ(count, current->value);
        count++;
        current = current->next;
    }
    ASSERT_EQ(nullptr, current);
}


/* For CountLength */
TEST(TestForLinkedListCount, should_count_simpe_0_to_10) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(0, 10);
    // WHEN
    int length = Solution::CountLength(head);
    // THEN
    ASSERT_EQ(11, length);
}

TEST(TestForLinkedListCount, should_count_null_pointer_as_0) {
    // GIVEN
    ListNode* head = nullptr;
    // WHEN
    int length = Solution::CountLength(head);
    // THEN
    ASSERT_EQ(0, length);
}

TEST(TestForLinkedListCount, should_count_single_node_as_1) {
    // GIVEN
    ListNode* head = new ListNode(2303);
    // WHEN
    int length = Solution::CountLength(head);
    // THEN
    ASSERT_EQ(1, length);
}


/* For AddNode */
TEST(TestForLinkedListAdd, should_add_999_between_998_and_1000) {
    // GIVEN
    ListNode* l1 = Solution::BuildFromXToY(990, 998);
    ListNode* l2 = Solution::BuildFromXToY(1000, 1024);
    ListNode* head = Helper::Concatenate(l1, l2); // 990->...->998->1000->...->1024

    // WHEN
    ListNode* result = Solution::AddNode(head, 999);

    // THEN
    ASSERT_NE(nullptr, result);

    int count = 990;
    ListNode* current = head;
    while(count <= 1024)
    {
        ASSERT_NE(nullptr, current);
        ASSERT_EQ(count, current->value);
        count++;
        current = current->next;
    }
    ASSERT_EQ(nullptr, current);
}

TEST(TestForLinkedListAdd, should_add_999_to_form_a_single_node_list_when_head_is_null) {
    // GIVEN
    ListNode* head = nullptr;
    // WHEN
    ListNode* result = Solution::AddNode(head, 999);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(result->value, 999);
    ASSERT_EQ(result->next, nullptr);
}

TEST(TestForLinkedListAdd, should_add_5_to_the_rear_of_234_returning_2345) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(2, 4);

    // WHEN
    ListNode* result = Solution::AddNode(head, 5);

    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(2, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(3, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(4, result->next->next->value);

    ASSERT_NE(nullptr, result->next->next->next);
    ASSERT_EQ(5, result->next->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next->next);
}

TEST(TestForLinkedListAdd, should_add_5_to_the_front_of_678_returning_5678) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(6, 8);

    // WHEN
    ListNode* result = Solution::AddNode(head, 5);

    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(5, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(6, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(7, result->next->next->value);

    ASSERT_NE(nullptr, result->next->next->next);
    ASSERT_EQ(8, result->next->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next->next);
}

TEST(TestForLinkedListAdd, should_get_12223_when_add_2_to_1223) {
    // GIVEN
    ListNode* l1 = Solution::BuildFromXToY(1, 2);
    ListNode* l2 = Solution::BuildFromXToY(2, 3);
    ListNode* head = Helper::Concatenate(l1, l2); // 1->2->2->3

    // WHEN
    ListNode* result = Solution::AddNode(head, 2);

    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(1, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(2, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(2, result->next->next->value);

    ASSERT_NE(nullptr, result->next->next->next);
    ASSERT_EQ(2, result->next->next->next->value);

    ASSERT_NE(nullptr, result->next->next->next->next);
    ASSERT_EQ(3, result->next->next->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next->next->next);
}


/* For DeleteNode */
TEST(TestForLinkedListDelete, should_return_nullptr_when_delete_anything_from_nullptr) {
    // GIVEN
    ListNode *head = nullptr;
    // WHEN
    ListNode *result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_EQ(nullptr, result);
}

TEST(TestForLinkedListDelete, should_return_124_when_delete_3_from_1234) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(1, 4);
    // WHEN
    ListNode* result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(1, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(2, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(4, result->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next);
}

TEST(TestForLinkedListDelete, should_delete_nothing_when_delete_3_from_4567) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(4, 7);
    // WHEN
    ListNode* result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(4, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(5, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(6, result->next->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(7, result->next->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next->next);
}

TEST(TestForLinkedListDelete, should_return_0_when_delete_1_from_0) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(0, 0);
    // WHEN
    ListNode* result = Solution::DeleteNode(head, 1);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(0, result->value);
    ASSERT_EQ(nullptr, result->next);
}

TEST(TestForLinkedListDelete, should_return_nullptr_when_delete_3_from_3) {
    // GIVEN
    ListNode *head = Solution::BuildFromXToY(3, 3);
    // WHEN
    ListNode *result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_EQ(nullptr, result);
}

TEST(TestForLinkedListDelete, should_return_456_when_delete_3_from_3456) {
    // GIVEN
    ListNode* head = Solution::BuildFromXToY(3, 6);
    // WHEN
    ListNode* result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(4, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(5, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(6, result->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next);
}

TEST(TestForLinkedListDelete, should_return_124_when_delete_3_from_12334) {
    // GIVEN
    ListNode* l1 = Solution::BuildFromXToY(1, 3);
    ListNode* l2 = Solution::BuildFromXToY(3, 4);
    ListNode* head = Helper::Concatenate(l1, l2);
    // WHEN
    ListNode* result = Solution::DeleteNode(head, 3);
    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(1, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(2, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(4, result->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next);
}

TEST(TestForLinkedListDelete, should_return_456_when_delete_3_from_334563) {
    // GIVEN
    ListNode* l1 = Solution::BuildFromXToY(3, 3);
    ListNode* l2 = Solution::BuildFromXToY(3, 6);
    ListNode* l12 = Helper::Concatenate(l1, l2);
    ListNode* l3 = Solution::BuildFromXToY(3, 3);
    ListNode* head = Helper::Concatenate(l12, l3);

    // WHEN
    ListNode* result = Solution::DeleteNode(head, 3);

    // THEN
    ASSERT_NE(nullptr, result);
    ASSERT_EQ(4, result->value);

    ASSERT_NE(nullptr, result->next);
    ASSERT_EQ(5, result->next->value);

    ASSERT_NE(nullptr, result->next->next);
    ASSERT_EQ(6, result->next->next->value);

    ASSERT_EQ(nullptr, result->next->next->next);
}
