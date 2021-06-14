#include <algorithm>
#include "gtest/gtest.h"
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Transform {
public:
    bool chkTransform(std::string A, int lena, std::string B, int lenb) {
        // write code here
        return std::is_permutation(A.begin(), A.end(), B.begin());
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Transform{}.chkTransform(" addcc", 5, "ac dc", 5), true);
}
