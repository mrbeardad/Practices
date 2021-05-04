#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <stack>

class CQueue {
    std::stack<int> inStack_;
    std::stack<int> outStack_;
public:
    CQueue() =default;

    void appendTail(int value)
    {
        inStack_.emplace(value);
    }

    int deleteHead()
    {
        if ( outStack_.empty() )
            for ( ; inStack_.size(); inStack_.pop() )
                outStack_.emplace(inStack_.top());

        if ( outStack_.empty() ) {
            return -1;
        } else {
            int ret{outStack_.top()};
            outStack_.pop();
            return ret;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

TEST(TestSuit, TestCase)
{

}
