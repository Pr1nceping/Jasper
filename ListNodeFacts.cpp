/**
 * This file defines a sort of test cases for the class named ListNode.
 *
 * You can read the code here getting some hints about what is required.
 *
 * But please do NOT change the code here.
 * You should implement the code logic in "src/ListNode.cpp" to pass all the tests.
 */

#include "gtest/gtest.h"
#include "Solution.h"


// NodeFacts
TEST(TestForListNode, ShouldSetZeroValueAndNullptrAsNextWhenUsingDefaultConstructor) {
    // GIVEN & WHEN
    ListNode* node = new ListNode();
    // THEN
    ASSERT_EQ(0, node->value);
    ASSERT_EQ(nullptr, node->next);
}

TEST(TestForListNode, ShouldCustomizeValueWhenUsingSecondConstructor) {
    // GIVEN
    int expectedValue = 2303;
    // WHEN
    ListNode* node = new ListNode(expectedValue);
    // THEN
    ASSERT_EQ(expectedValue, node->value);
    ASSERT_EQ(nullptr, node->next);
}

TEST(TestForListNode, ShouldCustomizeValueAndNextWhenUsingThirdConstructor) {
    // GIVEN
    int expectedValue = 3203;
    ListNode* rearNode = new ListNode();
    // WHEN
    ListNode* node = new ListNode(expectedValue, rearNode);
    // THEN
    ASSERT_EQ(expectedValue, node->value);
    ASSERT_EQ(rearNode, node->next);
}
