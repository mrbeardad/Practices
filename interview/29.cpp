#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class Solution {
public:

    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ret{};
        if ( matrix.empty() )
            return ret;

        ssize_t left{}, right{static_cast<ssize_t>(matrix[0].size()) - 1};
        ssize_t top{}, bot{static_cast<ssize_t>(matrix.size()) - 1};
        for ( ssize_t row{0}, col{-1}; left <= right; ) {
            for ( ; col < right; )
                ret.emplace_back(matrix[row][++col]);
            for ( ; row < bot; )
                ret.emplace_back(matrix[++row][col]);
            for ( ; col > left; )
                ret.emplace_back(matrix[row][--col]);
            for ( ; row > top + 1; )
                ret.emplace_back(matrix[--row][col]);
            ++left, --right, ++top, --bot;
        }
        return ret;
    }
};

TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{1,2,3},{4,5,6},{7,8,9}};
    std::vector<int> seq{1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(Solution{}.spiralOrder(matrix), seq);
}
