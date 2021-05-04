#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* half_node(ListNode* head)
{
    auto* fast = head;
    auto* slow = head;
    for ( ; fast != nullptr; ) {
        fast = fast->next_;
        if ( fast == nullptr )
            break;
        fast = fast->next_;
        slow = slow->next_;
    }
    return slow;
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5});
    EXPECT_EQ(half_node(ls)->val_, 3);
    ls = init_list({1,2,3,4,5,6});
    EXPECT_EQ(half_node(ls)->val_, 4);
}
