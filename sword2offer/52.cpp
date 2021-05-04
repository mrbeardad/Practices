#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* first_common_node(ListNode* lhs, ListNode* rhs)
{
    int len1{}, len2{};
    for ( auto* cur = lhs; cur != nullptr; cur = cur->next_ )
        ++len1;
    for ( auto* cur = rhs; cur != nullptr; cur = cur->next_ )
        ++len2;
    if ( len1 > len2 ) {
        for ( int cnter{len1 - len2}; cnter > 0; lhs = lhs->next_ );
    } else {
        for ( int cnter{len2 - len1}; cnter > 0; rhs = rhs->next_ );
    }
    for ( ; lhs != nullptr && rhs != nullptr && lhs != rhs; ) {
        lhs = lhs->next_;
        rhs = rhs->next_;
    }
    return lhs;
}

TEST(TestSuit, TestCase)
{
    auto* ls1 = init_list({1,2,3});
    auto* ls2 = init_list({4,5,6});
    auto* ls3 = init_list({7,8,9});
    EXPECT_EQ(first_common_node(ls1, ls2), nullptr);
    EXPECT_EQ(first_common_node(ls1, ls1), ls1);
    ls1->next_->next_->next_ = ls3;
    ls2->next_->next_->next_ = ls3;
    EXPECT_EQ(first_common_node(ls1, ls2), ls3);
}
