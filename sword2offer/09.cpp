#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <stack>

/*************************************************************************************************/
// 用两个栈实现队列
/*************************************************************************************************/
class QueueWithStack
{
    std::stack<int> pushStack_;
    std::stack<int> popStack_;
public:
    void push(int val)
    {
        pushStack_.push(val);
    }

    int pop()
    {
        // 由用户保证容器不为空
        if ( popStack_.empty() ) {
            for ( ; pushStack_.size(); ) {
                popStack_.push(pushStack_.top());
                pushStack_.pop();
            }
        }
        int ret{popStack_.top()};
        popStack_.pop();
        return ret;
    }
};

TEST(TestSuit, TestCase)
{
    QueueWithStack queue{};
    queue.push(1);
    queue.push(2);
    queue.push(3);
    EXPECT_EQ(queue.pop(), 1);
    queue.push(4);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_EQ(queue.pop(), 4);
}
