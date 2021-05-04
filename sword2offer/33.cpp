#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

template<typename Iter>
bool is_postorder(Iter begin, Iter end)
{
    if ( begin == end )
        return true;

    auto& rootVal = *--end;
    auto leftEnd = std::find_if(begin, end, [&rootVal](const auto& elem){return rootVal < elem;});
    if ( !std::all_of(leftEnd, end, [&rootVal](const auto& elem){return rootVal < elem;}) ) {
        return false;
    }
    return is_postorder(begin, leftEnd) && is_postorder(leftEnd, end);
}

TEST(TestSuit, TestCase)
{
    std::vector<int> postOrder{5,7,6,9,11,10,8};
    EXPECT_TRUE(is_postorder(postOrder.begin(), postOrder.end()));
    postOrder.assign({7,4,6,5});
    EXPECT_FALSE(is_postorder(postOrder.begin(), postOrder.end()));
}
