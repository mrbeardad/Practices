#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool is_stack_pop_seq(const std::vector<int>& pushSeq, const std::vector<int>& popSeq)
{
    std::vector<int> stack{};
    auto pushIter = pushSeq.begin();
    for ( int popVal : popSeq ) {
        if ( stack.size() && stack.back() == popVal ) {
            stack.pop_back();
        } else {
            auto tag = std::find(pushIter, pushSeq.end(), popVal);
            if ( tag == pushSeq.end() )
                return false;
            stack.insert(stack.end(), pushIter, tag);
            pushIter = tag + 1;
        }
    }
    return pushIter == pushSeq.end() && stack.empty();
}

TEST(TestSuit, TestCase)
{
    std::vector<int> pushSeq{1,2,3,4,5}, popSeq{4,5,3,2,1};
    EXPECT_TRUE(is_stack_pop_seq(pushSeq, popSeq));
    popSeq.assign({4,3,5,1,2});
    EXPECT_FALSE(is_stack_pop_seq(pushSeq, popSeq));
    popSeq.assign({4,5,3,2});
    EXPECT_FALSE(is_stack_pop_seq(pushSeq, popSeq));
}
