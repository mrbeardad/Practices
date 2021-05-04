#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

/*************************************************************************************************/
// 二维数组中数字，每行每列都呈递增序列，从中搜索目标数字
/*************************************************************************************************/
bool find_in_sorted_matrix(std::vector<std::vector<int> >& matrix, int key)
{
    if ( matrix.empty() || matrix[0].empty() )
        return false;

    ssize_t row{}, col{static_cast<ssize_t>(matrix[0].size()) - 1};
    for ( ; ; ) {
        for ( ; row < matrix.size() && matrix[row][col] < key; ++row );
        if ( row >= matrix.size() )
            return false;
        for ( ; col >= 0 && matrix[row][col] > key; --col );
        if ( col < 0 )
            return false;
        if ( matrix[row][col] == key )
            return true;
    }
}


TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{0,1,2},{2,3,4},{6,7,8}};
    EXPECT_EQ(find_in_sorted_matrix(matrix, 0), true);
    EXPECT_EQ(find_in_sorted_matrix(matrix, 2), true);
    EXPECT_EQ(find_in_sorted_matrix(matrix, 6), true);
    EXPECT_EQ(find_in_sorted_matrix(matrix, 8), true);
    EXPECT_EQ(find_in_sorted_matrix(matrix, -1), false);
    EXPECT_EQ(find_in_sorted_matrix(matrix, 5), false);
    EXPECT_EQ(find_in_sorted_matrix(matrix, 9), false);
    matrix.clear();
    EXPECT_EQ(find_in_sorted_matrix(matrix, 9), false);
}
