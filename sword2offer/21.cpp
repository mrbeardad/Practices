#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename Itr, typename Func>
Itr mypartition(Itr begin, Itr end, Func check)
{
    for ( ; ; ) {
        for ( ; begin != end && check(*begin); ++begin );
        if ( begin == end )
            break;
        std::iter_swap(begin, --end);
    }
    return begin;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> ls{1,2,3,4,5,6};
    auto mid = mypartition(ls.begin(), ls.end(), [](int elem){return elem & 0x1;});

    ls.clear();
    mid = mypartition(ls.begin(), ls.end(), [](int elem){return elem & 0x1;});

    // std::vector<int> ls2{1,3,5,2,4,6};
    // EXPECT_EQ(ls, ls2);
    // EXPECT_EQ(*mid, 2);
}
