#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

int depth(TreeNode* root)
{
    if ( root == nullptr )
        return 0;
    int childDepth{std::max(depth(root->left_), depth(root->right_))};
    return childDepth + 1;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({5,3,2,-1,-1,4,-1,-1,7,6,-1,-1,8,-1,-1});
    EXPECT_EQ(depth(bt), 3);
    bt = init_btree({5,4,3,2,1,-1,-1,-1,-1,-1});
    EXPECT_EQ(depth(bt), 5);
    EXPECT_EQ(depth(nullptr), 0);
}
