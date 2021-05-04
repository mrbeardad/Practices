#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<int> print_matrix_circle(const std::vector<std::vector<int> >& matrix)
{
    std::vector<int> ret{};
    if ( matrix.empty() || matrix[0].empty() )
        return ret;
    ssize_t left{}, right{static_cast<ssize_t>(matrix[0].size()) - 1};
    ssize_t top{}, bot{static_cast<ssize_t>(matrix.size()) - 1};
    for ( ssize_t row{}, col{-1}; ; ) {
        for ( ; col < right; )
            ret.emplace_back(matrix[row][++col]);
        for ( ; row < bot; )
            ret.emplace_back(matrix[++row][col]);
        if ( left >= right || top >= bot )
            break;
        for ( ; col > left; )
            ret.emplace_back(matrix[row][--col]);
        for ( ; row > top + 1; )
            ret.emplace_back(matrix[--row][col]);
        ++left, --right, ++top, --bot;
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    std::vector<int> printed{1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10};
    EXPECT_EQ(print_matrix_circle(matrix), printed);

    matrix.assign({{1,2,3},{4,5,6},{7,8,9},{10,11,12}});
    printed.assign({1,2,3,6,9,12,11,10,7,4,5,8});
    EXPECT_EQ(print_matrix_circle(matrix), printed);
}
