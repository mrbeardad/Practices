#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* merge_list(ListNode* lhs, ListNode* rhs)
{
    ListNode dummy{};
    auto* tail = &dummy;
    for ( ; lhs != nullptr && rhs != nullptr; ) {
        if ( lhs->val_ < rhs->val_ ) {
            tail->next_ = new ListNode{lhs->val_};
            lhs = lhs->next_;
        } else {
            tail->next_ = new ListNode{rhs->val_};
            rhs = rhs->next_;
        }
        tail = tail->next_;
    }
    for ( ; lhs != nullptr; lhs = lhs->next_ ) {
        tail->next_ = new ListNode{lhs->val_};
        tail = tail->next_;
    }
    for ( ; rhs != nullptr; rhs = rhs->next_ ) {
        tail->next_ = new ListNode{rhs->val_};
        tail = tail->next_;
    }
    return dummy.next_;
}

TEST(TestSuit, TestCase)
{
    auto* ls1 = init_list({1,3,5});
    auto* ls2 = init_list({2,4,6});
    auto* ls3 = init_list({1,2,3,4,5,6});
    EXPECT_EQ(compare(merge_list(ls1, ls2), ls3), 0);
    EXPECT_EQ(compare(merge_list(ls1, nullptr), ls1), 0);
    EXPECT_EQ(compare(merge_list(nullptr, ls2), ls2), 0);
    EXPECT_EQ(compare(merge_list(nullptr, nullptr), nullptr), 0);
}
