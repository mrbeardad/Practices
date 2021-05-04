#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

class CharStatistics
{
    std::unordered_map<char, int> idx_;
    size_t curIdx_;
public:
    void push(char val)
    {
        auto tag = idx_.find(val);
        if ( tag == idx_.end() )
            idx_.emplace(val, curIdx_);
        else
            tag->second = std::numeric_limits<int>::max();
        ++curIdx_;
    }

    char get_first()
    {
        auto ret = std::min_element(idx_.begin(), idx_.end(), [] (auto& lhs, auto& rhs) {
                return lhs.second < rhs.second;
                });
        return ret->second == std::numeric_limits<int>::max() ? '\0' : ret->first;
    }
};

TEST(TestSuit, TestCase)
{
    CharStatistics cs{};
    cs.push('a');
    EXPECT_EQ(cs.get_first(), 'a');
    cs.push('b');
    EXPECT_EQ(cs.get_first(), 'a');
    cs.push('a');
    EXPECT_EQ(cs.get_first(), 'b');
    cs.push('b');
    EXPECT_EQ(cs.get_first(), '\0');
    cs.push('c');
    EXPECT_EQ(cs.get_first(), 'c');
}
