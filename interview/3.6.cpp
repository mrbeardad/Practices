#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Reverse {
public:
    std::string& reverseSentence(std::string& A, int n) {
        // write code here
        std::reverse(A.begin(), A.end());
        for ( auto left{A.begin()}; ; ) {
            for ( ; left < A.end() && !std::isalpha(*left); ++left );
            if ( left == A.end() )
                break;
            auto right{left + 1};
            for ( ; right < A.end() && std::isalpha(*(right)); ++right );
            std::reverse(left, right);
            left = right;
        }
        return A;
    }
};


TEST(TestSuit, TestCase)
{
    std::string s{"yellow dog love cat"};
    EXPECT_EQ(Reverse{}.reverseSentence(s, s.size()), "cat love dog yellow");
}
