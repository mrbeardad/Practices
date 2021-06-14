#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Prior {
public:
    std::string findSmallest(std::vector<std::string> strs, int n) {
        // write code here
        std::sort(strs.begin(), strs.end(), [] (std::string& lhs, std::string& rhs) {
            return lhs + rhs < rhs + lhs;
        });
        std::string ans{std::accumulate(strs.begin(), strs.end(), std::string{})};
        return ans;
    }
};


TEST(TestSuit, TestCase)
{

}
