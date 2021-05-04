#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class ThreeColor {
public:
    std::vector<int>& sortThreeColor(std::vector<int>& A, int n) {
        // write code here
        ssize_t left1{}, right2{n - 1};
        for ( ssize_t idx{}; idx <= right2; ) {
            if ( A.at(idx) == 0 )
                std::swap(A.at(left1++), A.at(idx++));
            else if ( A.at(idx) == 2 )
                std::swap(A.at(right2--), A.at(idx));
            else
                ++idx;
        }
        return A;
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<int> a{0, 2, 1, 1, 2}, result{0, 1, 1, 2, 2};
    ThreeColor{}.sortThreeColor(a, a.size());
    EXPECT_EQ(a, result);
}
