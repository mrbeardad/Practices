#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Replacement {
public:
    std::string replaceSpace(std::string iniString, int length) {
        // write code here
        ssize_t right{length + 2 * std::count(iniString.begin(), iniString.begin() + length, ' ') - 1};
        iniString.resize(right + 1);
        ssize_t last{length - 1};
        for ( ; last >= 0; --last ) {
            if ( iniString.at(last) == ' ' ) {
                iniString.at(right--) = '0';
                iniString.at(right--) = '2';
                iniString.at(right--) = '%';
            } else {
                iniString.at(right--) = iniString.at(last);
            }
        }
        return iniString;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Replacement{}.replaceSpace("a b c    ", 5), "a%20b%20c");
}
