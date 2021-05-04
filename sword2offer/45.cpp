#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename Iter, typename Comp=std::less<typename Iter::value_type> >
void sort_seqs(Iter begin, Iter end, Comp comp=Comp{})
{
    std::sort(begin, end, [&comp] (auto& lhs, auto& rhs) {
        return comp(lhs + rhs, rhs + lhs);
    });
}

TEST(TestSuit, TestCase)
{
    std::vector<std::string> nums{"1", "10", "23"}, sorted{"10", "1", "23"};
    sort_seqs(nums.begin(), nums.end());
    EXPECT_EQ(nums, sorted);
}
