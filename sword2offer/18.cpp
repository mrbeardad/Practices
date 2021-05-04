#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

void delete_node(ListNode*& head, ListNode* needDel)
{
    if ( head == nullptr || needDel == nullptr )
        return;

    if ( needDel->next_ != nullptr ) {
        needDel->val_ = needDel->next_->val_;
        auto* next = needDel->next_->next_;
        delete needDel->next_;
        needDel->next_ = next;
    } else {
        ListNode dummy{};
        dummy.next_ = head;
        auto* prev = &dummy;
        auto* cur = head;
        for ( ; cur->next_ != nullptr; prev = prev->next_, cur = cur->next_ );
        auto* next = cur->next_;
        delete cur;
        prev->next_ = next;
        head = dummy.next_;
    }
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5,6});
    delete_node(ls, ls);
    auto* ls1 = init_list({2,3,4,5,6});
    EXPECT_EQ(compare(ls, ls1), 0);

    delete_node(ls, ls->next_);
    auto* ls2 = init_list({2,4,5,6});
    EXPECT_EQ(compare(ls, ls2), 0);

    delete_node(ls, ls->next_->next_->next_);
    auto* ls3 = init_list({2,4,5});
    EXPECT_EQ(compare(ls, ls3), 0);

    delete_node(ls, ls->next_);
    delete_node(ls, ls->next_);
    EXPECT_EQ(compare(ls, init_list({2})), 0);
    delete_node(ls, ls);
    EXPECT_EQ(compare(ls, nullptr), 0);
    delete_node(ls, ls);
    EXPECT_EQ(compare(ls, nullptr), 0);
}
