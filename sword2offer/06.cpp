#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include <simple_list.hpp>

/*************************************************************************************************/
// 逆向打印单向链表
/*************************************************************************************************/
std::vector<int> reverse_print_list(ListNode* head)
{
    std::vector<int> ret{};
    for ( ; head != nullptr; head = head->next_ )
        ret.emplace_back(head->val_);
    std::reverse(ret.begin(), ret.end());
    return ret;
}


TEST(TestSuit, TestCase)
{
    ListNode ls{0,1,2,3,4,5};
    std::vector<int> v{5,4,3,2,1,0};
    EXPECT_EQ(reverse_print_list(&ls), v);

    ListNode ls2{};
    v.assign({0});
    EXPECT_EQ(reverse_print_list(&ls2), v);

    v.clear();
    EXPECT_EQ(reverse_print_list(nullptr), v);
}
