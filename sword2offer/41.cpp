#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>

#include "simple_btree.hpp"

class GetMidian
{
    std::priority_queue<int> lowerHeap_;
    std::priority_queue<int, std::vector<int>, std::greater<int> > upperHeap_;
public:
    void push(int val)
    {
        upperHeap_.emplace(val);
        if ( upperHeap_.size() > lowerHeap_.size() ) {
            lowerHeap_.emplace(upperHeap_.top());
            upperHeap_.pop();
        } else if ( upperHeap_.top() < lowerHeap_.top() ) {
            upperHeap_.emplace(lowerHeap_.top());
            lowerHeap_.emplace(upperHeap_.top());
            upperHeap_.pop();
            lowerHeap_.pop();
        }
    }

    double get_midian()
    {
        if ( lowerHeap_.size() > upperHeap_.size() )
            return lowerHeap_.top();
        else
            return (lowerHeap_.top() + upperHeap_.top()) / 2.0;
    }
};

TEST(TestSuit, TestCase)
{
    GetMidian gm{};
    gm.push(1);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1);
    gm.push(2);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1.5);
    gm.push(1);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1);
    gm.push(0);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1);
    gm.push(4);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1);
    gm.push(5);
    EXPECT_DOUBLE_EQ(gm.get_midian(), 1.5);
}
