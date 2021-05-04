#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int max_path(const std::vector<std::vector<int> >& matrix)
{
    auto dp = matrix;
    for ( size_t row{}; row < matrix.size(); ++row ) {
        for ( size_t col{}; col < matrix[row].size(); ++col ) {
            if ( row != 0 || col != 0 ) {
                if ( row == 0 )
                    dp[row][col] = dp[row][col - 1] + matrix[row][col];
                else if ( col == 0 )
                    dp[row][col] = dp[row - 1][col] + matrix[row][col];
                else
                    dp[row][col] = std::max(dp[row][col - 1], dp[row - 1][col]) + matrix[row][col];
            }
        }
    }
    // 由用户负责输入有效
    return dp.back().back();
}

TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
    EXPECT_EQ(max_path(matrix), 53);
    matrix.assign({{1,2,3,4}});
    EXPECT_EQ(max_path(matrix), 10);
    matrix.assign({{1},{2},{3},{4}});
    EXPECT_EQ(max_path(matrix), 10);
}
