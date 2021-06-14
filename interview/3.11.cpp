#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Parenthesis {
public:
    bool chkParenthesis(std::string& A, int n) {
        // write code here
        int leftCnt{};
        for ( char thisChar : A ) {
            if ( thisChar == '(' )
                ++leftCnt;
            else if ( thisChar == ')' )
                --leftCnt;
            if ( leftCnt < 0 )
                return false;
        }
        if ( leftCnt == 0 )
            return true;
        else
            return false;
    }
};


TEST(TestSuit, TestCase)
{

}
