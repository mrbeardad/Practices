#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

struct ListNode
{
    int         val_;
    ListNode*   next_;
};

ListNode* lastK(ListNode* head, int k)
{
    int step{};
    ListNode* curNode{head};
    for ( ; curNode != nullptr && step < k; ++step )    // nullptr为尾后节点
        curNode = curNode->next_;
    if ( step != k )
        return nullptr;
    for ( ; curNode != nullptr; ) {
        head = head->next_;
        curNode = curNode->next_;
    }
    return head;
}

TEST(TestSuit, TestCase)
{
    auto* ls = new ListNode{5, new ListNode{4, new ListNode{3, new ListNode{2, new ListNode{1, nullptr}}}}};
    EXPECT_EQ(lastK(ls, 5)->val_, 5);
    EXPECT_EQ(lastK(ls, 4)->val_, 4);
    EXPECT_EQ(lastK(ls, 3)->val_, 3);
    EXPECT_EQ(lastK(ls, 2)->val_, 2);
    EXPECT_EQ(lastK(ls, 1)->val_, 1);

}
