#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<int> max_in_window(const std::vector<int>& nums, unsigned winsize)
{
    std::vector<int> ret{};
    if ( winsize == 0 )
        return ret;

    std::deque<std::pair<int, size_t> > monoQueue{};
    auto push = [&monoQueue, &nums] (size_t idx) {
        for ( ; monoQueue.size() && monoQueue.back().first < nums[idx]; )
            monoQueue.pop_back();
        monoQueue.emplace_back(nums[idx], idx);
    };

    for ( size_t idx{}; idx < nums.size(); ++idx ) {
        push(idx);
        if ( idx - monoQueue.front().second + 1 > winsize )
            monoQueue.pop_front();
        if ( idx >= winsize - 1 )
            ret.emplace_back(monoQueue.front().first);
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{2,3,4,2,6,2,5,1}, ans{4,4,6,6,6,5};
    EXPECT_EQ(max_in_window(nums, 3), ans);
}
