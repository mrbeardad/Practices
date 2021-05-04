#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int get_kth_num(int kth)
{
    if ( kth <= 10 )
        return kth - 1;

    int digit{1}, pow{1}, numCnt{10};
    for ( ; numCnt < kth; ) {
        ++digit;
        pow *= 10;
        numCnt += 9 * pow * digit;
    }
    int numNr{kth - numCnt + 9 * pow * digit - 1};
    int tagNum{numNr / digit + pow};
    int tagNumIdxFromRight{digit - numNr % digit};
    for ( ; tagNumIdxFromRight > 1; --tagNumIdxFromRight )
        tagNum /= 10;
    return tagNum % 10;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(get_kth_num(1), 0);
    EXPECT_EQ(get_kth_num(9), 8);
    EXPECT_EQ(get_kth_num(10), 9);
    EXPECT_EQ(get_kth_num(11), 1);
    EXPECT_EQ(get_kth_num(12), 0);
    EXPECT_EQ(get_kth_num(13), 1);
    EXPECT_EQ(get_kth_num(14), 1);
}
