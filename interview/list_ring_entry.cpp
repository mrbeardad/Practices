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

ListNode* find_ring_entry(ListNode* head)
{
    ListNode* pStep1{head};
    ListNode* pStep2{head};
    for ( ; pStep2 != nullptr; ) {
        pStep2 = pStep2->next_;
        if ( pStep2 == pStep1 )
            break;

        if ( pStep2 != nullptr )
            pStep2 = pStep2->next_;
        else
            break;
        if ( pStep2 == pStep1 )
            break;
        pStep1 = pStep1->next_;
        if ( pStep2 == pStep1 )
            break;
    }
    if ( pStep2 == nullptr )
        return pStep2;
    int cnt1{}, cnt2{};
    for ( ; pStep1 != pStep2; ) {
        pStep2 = pStep2->next_;
        ++cnt2;
        if ( pStep2 == pStep1 )
            break;
        pStep2 = pStep2->next_;
        ++cnt2;
        if ( pStep2 == pStep1 )
            break;
        pStep1 = pStep1->next_;
        ++cnt1;
        if ( pStep2 == pStep1 )
            break;
    }
    ListNode* prev{head};
    ListNode* cur{head};
    for ( ; cnt1 < cnt2; ++cnt1 )
        cur = cur->next_;
    for ( ; prev != cur; ) {
        cur = cur->next_;
        prev = prev->next_;
    }
    return prev;
}

TEST(TestSuit, TestCase)
{
    ListNode l1{1}, l2{2}, l3{3}, l4{4}, l5{5};
    l1.next_ = &l2;
    l2.next_ = &l3;
    l3.next_ = &l4;
    l4.next_ = &l5;
    EXPECT_EQ(find_ring_entry(&l1), nullptr);
    l5.next_ = &l1;
    EXPECT_EQ(find_ring_entry(&l1), &l1);
    l5.next_ = &l4;
    EXPECT_EQ(find_ring_entry(&l1)->val_, l4.val_);
    l5.next_ = &l5;
    EXPECT_EQ(find_ring_entry(&l1)->val_, l5.val_);
    l2.next_ = &l1;
    EXPECT_EQ(find_ring_entry(&l1), &l1);
    l1.next_ = &l1;
    EXPECT_EQ(find_ring_entry(&l1), &l1);
}
