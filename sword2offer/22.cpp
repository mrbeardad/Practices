#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* find_kth_to_tail(ListNode* head, int kth)
{
    if ( kth < 1 || head == nullptr )
        return nullptr;

    auto* fast = head;
    for ( ;fast != nullptr && kth > 0; fast = fast->next_ )
        --kth;
    if ( kth != 0 )
        return nullptr;

    auto* slow = head;
    for ( ; fast != nullptr; fast = fast->next_ )
        slow = slow->next_;

    return slow;
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5,6});

    EXPECT_EQ(find_kth_to_tail(ls, 0), nullptr);
    EXPECT_EQ(find_kth_to_tail(ls, 1)->val_, 6);
    EXPECT_EQ(find_kth_to_tail(ls, 2)->val_, 5);
    EXPECT_EQ(find_kth_to_tail(ls, 6)->val_, 1);
    EXPECT_EQ(find_kth_to_tail(ls, 7), nullptr);
    EXPECT_EQ(find_kth_to_tail(nullptr, 7), nullptr);
}
