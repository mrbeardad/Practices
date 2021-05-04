#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

ListNode* reverse_list(ListNode* head)
{
    ListNode* prev = nullptr;
    auto* cur = head;
    for ( ; cur != nullptr; ) {
        auto* next = cur->next_;
        cur->next_ = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5});
    auto* sl = init_list({5,4,3,2,1});
    EXPECT_EQ(compare(reverse_list(ls), sl), 0);
}
