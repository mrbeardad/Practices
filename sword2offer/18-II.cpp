#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_list.hpp"

void delete_duplicated(ListNode*& head)
{
    if ( head == nullptr )
        return;

    ListNode dummy{0, head};
    auto* prev = &dummy;
    auto* cur = head;
    for ( ; cur != nullptr; ) {
        if ( cur->next_ != nullptr && cur->next_->val_ == cur->val_ ) {
            int delVal{cur->val_};
            for ( ; cur != nullptr && cur->val_ == delVal; ) {
                auto* next = cur->next_;
                delete cur;
                cur = next;
            }
            prev->next_ = cur;
        } else {
            prev = cur;
            cur = cur->next_;
        }
    }
    head = dummy.next_;
}

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5});
    delete_duplicated(ls);
    EXPECT_EQ(compare(ls, init_list({1,2,3,4,5})), 0);

    ls = init_list({1,2,3,3,4,4,5});
    delete_duplicated(ls);
    EXPECT_EQ(compare(ls, init_list({1,2,5})), 0);

    ls = init_list({1,2,3,3,4,5,5});
    delete_duplicated(ls);
    EXPECT_EQ(compare(ls, init_list({1,2,4})), 0);

    ls = init_list({1,1,2,2,3,3,4,4,5,5});
    delete_duplicated(ls);
    EXPECT_EQ(compare(ls, init_list({})), 0);
}
