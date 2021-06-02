#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

#include "simple_list.hpp"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0, head};
        head = &dummy;
        for ( ; ; ) {
            ListNode* tail{head};
            for ( int step{}; tail != nullptr && step < k; ++step )
                tail = tail->next_;
            if ( tail == nullptr )
                break;
            ListNode* nextTail{tail->next_};
            for ( ListNode* prev{head}, *cur{head->next_}; cur != nextTail; ) {
                ListNode* next{cur->next_};
                cur->next_ = prev;
                prev = cur;
                cur = next;
            }
            ListNode* newTail{head->next_};
            head->next_ = tail;
            newTail->next_ = nextTail;

            head = newTail;
        }
        return dummy.next_;
    }
};

TEST(TestSuit, TestCase)
{
    auto* ls = init_list({1,2,3,4,5});
    auto* ls2 = init_list({2,1,4,3,5});
    ls = Solution{}.reverseKGroup(ls, 2);
    EXPECT_EQ(compare(ls, ls2), 0);
}
