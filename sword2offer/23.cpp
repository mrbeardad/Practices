#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* find_ring_begin(ListNode* head)
{
    auto* fast = head;
    auto* slow = head;
    for ( ; ; ) {
        if ( fast == nullptr )
            break;
        fast = fast->next_;
        if ( fast == nullptr )
            break;
        fast = fast->next_;
        slow = slow->next_;
        if ( fast == slow )
            break;
    }
    // 无环
    if ( fast == nullptr )
        return nullptr;
    int cnterFast{}, cnterSlow{};
    for ( ; ; ) {
        fast = fast->next_->next_;
        cnterFast += 2;
        slow = slow->next_;
        cnterSlow += 1;
        if ( fast == slow )
            break;
    }
    fast = slow = head;
    for ( int step{cnterFast - cnterSlow}; step > 0; --step )
        fast = fast->next_;
    for ( ; fast != slow; fast = fast->next_ )
        slow = slow->next_;
    return slow;
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5});
    EXPECT_EQ(find_ring_begin(ls), nullptr);

    ls = init_list({1,2,3,4});
    ls->next_->next_->next_->next_ = ls->next_->next_->next_;
    EXPECT_EQ(find_ring_begin(ls)->val_, 4);

    ls->next_->next_->next_->next_ = ls->next_->next_;
    EXPECT_EQ(find_ring_begin(ls)->val_, 3);

    ls->next_->next_->next_->next_ = ls;
    EXPECT_EQ(find_ring_begin(ls)->val_, 1);

    EXPECT_EQ(find_ring_begin(nullptr), nullptr);
}
