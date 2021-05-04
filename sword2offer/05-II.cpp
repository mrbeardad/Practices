#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

/*************************************************************************************************/
// 归并两有序数组
/*************************************************************************************************/
std::vector<int>& merge_sorted_array(std::vector<int>& lhs, const std::vector<int>& rhs)
{
    ssize_t lhsIdx{static_cast<ssize_t>(lhs.size()) - 1}, rhsIdx{static_cast<ssize_t>(rhs.size()) - 1};
    lhs.resize(lhs.size() + rhs.size());
    ssize_t lastIdx{static_cast<ssize_t>(lhs.size()) - 1};
    for ( ; lhsIdx >= 0 && rhsIdx >= 0; --lastIdx ) {
        if ( lhs[lhsIdx] > rhs[rhsIdx] )
            lhs[lastIdx] = lhs[lhsIdx--];
        else
            lhs[lastIdx] = rhs[rhsIdx--];
    }
    for ( ; lhsIdx >= 0; --lhsIdx )
        lhs[lastIdx--] = lhs[lhsIdx];
    for ( ; rhsIdx >= 0; --rhsIdx )
        lhs[lastIdx--] = rhs[rhsIdx];
    return lhs;
}


TEST(TestSuit, TestCase)
{
    std::vector<int> lhs{1,3,5,7,9}, rhs{0,2,4,6,8}, merged{0,1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(merge_sorted_array(lhs, rhs), merged);
    lhs.clear();
    merged = rhs;
    EXPECT_EQ(merge_sorted_array(lhs, rhs), merged);
    rhs.clear();
    EXPECT_EQ(merge_sorted_array(lhs, rhs), merged);
    lhs.clear();
    merged.clear();
    EXPECT_EQ(merge_sorted_array(lhs, rhs), merged);
}
