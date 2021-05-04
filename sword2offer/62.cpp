#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int last_remaining(int count, int step)
{
    int lastRemainIdx{}, curCount{1};
    for ( ; ++curCount <= count; ) {
        lastRemainIdx = (lastRemainIdx + step) % curCount;
    }
    return lastRemainIdx;
}

TEST(TestSuit, TestCase)
{

}
