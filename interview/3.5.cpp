#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Rotation {
public:
    bool chkRotation(std::string A, int lena, std::string B, int lenb) {
        // write code here
        A = A + A;
        return A.find(B) != std::string::npos;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Rotation{}.chkRotation("abcd", 4, "cdab", 4), true);
    EXPECT_EQ(Rotation{}.chkRotation("abdc", 4, "cdab", 4), false);
}
