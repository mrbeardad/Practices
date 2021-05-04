#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

class GetMaxQueue
{
    std::deque<std::pair<int, size_t> > queue_;
    std::deque<std::pair<int, size_t> > monoQue_;
    size_t curIdx_;
public:
    void push(int val)
    {
        queue_.emplace_back(val, curIdx_);
        for ( ; monoQue_.size() && monoQue_.back().first < val; )
            monoQue_.pop_back();
        monoQue_.emplace_back(val, curIdx_);
        ++curIdx_;
    }

    int pop()
    {
        if ( queue_.front().second == monoQue_.front().second )
            monoQue_.pop_front();
        int ret{queue_.front().first};
        queue_.pop_front();
        return ret;
    }

    int get_max()
    {
        return monoQue_.front().first;
    }
};

TEST(TestSuit, TestCase)
{
    GetMaxQueue gmq{};
    gmq.push(1);
    EXPECT_EQ(gmq.get_max(), 1);
    gmq.push(2);
    EXPECT_EQ(gmq.get_max(), 2);
    gmq.push(3);
    EXPECT_EQ(gmq.get_max(), 3);
    gmq.pop();
    EXPECT_EQ(gmq.get_max(), 3);
    gmq.pop();
    EXPECT_EQ(gmq.get_max(), 3);
    gmq.push(0);
    EXPECT_EQ(gmq.get_max(), 3);
}
