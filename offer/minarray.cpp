#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Solution {
public:
    int minArray(const std::vector<int>& numbers)
    {
        if ( numbers.empty() )
            return std::numeric_limits<int>::min();

        if ( numbers.front() < numbers.back() )
            return numbers.front();

        size_t left{}, right{numbers.size() - 1};
        for ( ; right - left > 1; ) {
            size_t mid{(left + right) / 2};
            if ( numbers[left] == numbers[right] && numbers[mid] == numbers[left] ) {
                for ( ; left < right && numbers[left + 1] == numbers[left]; ++left );
                for ( ; left < right && numbers[right - 1] == numbers[right]; --right );
            } else if ( numbers[mid] >= numbers[left] ) {
                left = mid;
            } else if ( numbers[mid] <= numbers[left] ) {
                right = mid;
            }
        }
        return numbers[right];
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.minArray({3,4,5,1,2}), 1);
    EXPECT_EQ(Solution{}.minArray({3,3,1,3}), 1);
    EXPECT_EQ(Solution{}.minArray({3,1,3,3,3}), 1);
    EXPECT_EQ(Solution{}.minArray({1,1,1}), 1);
}
