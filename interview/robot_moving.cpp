#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>


class Solution {
    std::unordered_map<size_t, bool> visited_;
    size_t  rows_;
    size_t  cols_;
    int     maxK_;
public:
    int movingCount(int m, int n, int k) {
        rows_ = m;
        cols_ = n;
        maxK_ = k;
        return count(0, 0);
    }

    int count(size_t row, size_t col)
    {
        auto check = [this] (size_t row, size_t col) {
            int sum{};
            for ( ; row; row /= 10 )
                sum += row % 10;
            for ( ; col; col /= 10 )
                sum += col % 10;
            return sum > maxK_ ? false : true;
        };

        size_t key{row * cols_ + col};
        if ( row >= rows_ || col >= cols_ || visited_[key] || !check(row, col) )
            return 0;
        visited_[key] = true;
        return 1 + count(row - 1, col) + count(row + 1, col) + count(row, col - 1) + count(row, col + 1);
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.movingCount(2, 3, 1), 3);
    EXPECT_EQ(Solution{}.movingCount(3, 1, 0), 1);
}
