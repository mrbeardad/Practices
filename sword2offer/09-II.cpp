#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>


/*************************************************************************************************/
// 用两个队列实现栈
/*************************************************************************************************/
class StackWithQueue
{
    std::queue<int> que1_;
    std::queue<int> que2_;
public:
    void push(int val)
    {
        if ( que1_.size() )
            que1_.push(val);
        else
            que2_.push(val);
    }

    int pop()
    {
        auto* popQue = que1_.size() ? &que1_ : &que2_;
        auto* pushQue = que1_.empty() ? &que1_ : &que2_;

        for ( ; popQue->size() > 1; ) {
            pushQue->push(popQue->front());
            popQue->pop();
        }
        // 由调用者保证容器不为空
        int ret{popQue->front()};
        popQue->pop();
        return ret;
    }
};


TEST(TestSuit, TestCase)
{
    StackWithQueue swq{};
    swq.push(1);
    swq.push(2);
    swq.push(3);
    EXPECT_EQ(swq.pop(), 3);
    swq.push(4);
    swq.push(5);
    EXPECT_EQ(swq.pop(), 5);
    EXPECT_EQ(swq.pop(), 4);
    EXPECT_EQ(swq.pop(), 2);
    EXPECT_EQ(swq.pop(), 1);
}
