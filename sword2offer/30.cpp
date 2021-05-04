#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <stack>

class MinStack
{
    std::stack<int> stack_;
    std::stack<int> min_;
public:
    void push(int val)
    {
        min_.push(min_.empty() ? val : std::min(min_.top(), val));
        stack_.push(val);
    }

    int pop()
    {
        int ret{stack_.top()};
        stack_.pop();
        min_.pop();
        return ret;
    }

    int get_min()
    {
        return min_.top();
    }
};

TEST(TestSuit, TestCase)
{
    MinStack ms{};
    ms.push(1);
    EXPECT_EQ(ms.get_min(), 1);
    ms.push(2);
    EXPECT_EQ(ms.get_min(), 1);
    ms.push(3);
    EXPECT_EQ(ms.get_min(), 1);
    ms.push(0);
    EXPECT_EQ(ms.get_min(), 0);

    EXPECT_EQ(ms.pop(), 0);
    EXPECT_EQ(ms.get_min(), 1);
    EXPECT_EQ(ms.pop(), 3);
    EXPECT_EQ(ms.get_min(), 1);
    EXPECT_EQ(ms.pop(), 2);
    EXPECT_EQ(ms.get_min(), 1);
    EXPECT_EQ(ms.pop(), 1);
}
