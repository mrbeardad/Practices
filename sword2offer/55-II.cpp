#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

bool isAVL(TreeNode* root, int& depth)
{
    if ( root == nullptr ) {
        depth = 0;
        return true;
    }
    int leftDepth{}, rightDepth{};
    bool isChildBothAVL{isAVL(root->left_, leftDepth) && isAVL(root->right_, rightDepth)};
    depth = std::max(leftDepth, rightDepth) + 1;
    return isChildBothAVL && std::abs(leftDepth - rightDepth) <= 1;
}

bool isAVL(TreeNode* root)
{
    int depth{};
    return isAVL(root, depth);
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({0,0,0,-1,-1,0,-1,-1,0,0,-1,-1,0,-1,-1});
    EXPECT_TRUE(isAVL(bt));
    bt = init_btree({0,0,0,-1,-1,0,-1,-1,0,0,-1,-1,-1});
    EXPECT_TRUE(isAVL(bt));
    bt = init_btree({0,0,0,-1,-1,0,-1,-1,0,-1,-1});
    EXPECT_TRUE(isAVL(bt));
    bt = init_btree({0,0,0,-1,-1,0,-1,-1,-1});
    EXPECT_FALSE(isAVL(bt));

    bt = init_btree({0,0,0,-1,-1,-1});
    EXPECT_FALSE(isAVL(bt));
    bt = init_btree({0,-1,0,-1,0,-1,-1});
    EXPECT_FALSE(isAVL(bt));
}
