#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Finder {
public:
    bool findX(std::vector<std::vector<int> > matrix, int n, int m, int x) {
        // write code here
        for ( ssize_t row{}, col{m - 1}; ; ) {
            for ( ; row < n && matrix.at(row).at(col) < x; ++row );
            if ( row == n )
                break;
            else if ( matrix.at(row).at(col) == x )
                return true;
            for ( ; col >= 0 && matrix.at(row).at(col) > x; --col );
            if ( col < 0 )
                break;
            else if ( matrix.at(row).at(col) == x )
                return true;
        }
        return false;
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<std::vector<int> > matrix{{1,2,3,4},{2,3,4,5},{4,5,6,7},{5,6,7,8}};
    EXPECT_EQ(Finder{}.findX(matrix, 4, 4, 4), true);
    EXPECT_EQ(Finder{}.findX(matrix, 4, 4, 1), true);
    EXPECT_EQ(Finder{}.findX(matrix, 4, 4, 5), true);
    EXPECT_EQ(Finder{}.findX(matrix, 4, 4, 8), true);
    EXPECT_EQ(Finder{}.findX(matrix, 4, 4, 9), false);
}
