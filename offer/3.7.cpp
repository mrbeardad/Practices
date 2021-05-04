#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Translation {
public:
    std::string stringTranslation(std::string A, int n, int len) {
        // write code here
        // std::rotate(A.begin(), A.begin() + len, A.end());
        std::reverse(A.begin(), A.begin() + len);
        std::reverse(A.begin() + len, A.end());
        std::reverse(A.begin(), A.end());
        return A;
    }
};


TEST(TestSuit, TestCase)
{

}
