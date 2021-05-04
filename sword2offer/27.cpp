#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

TreeNode* mirror(TreeNode* root)
{
    if ( root == nullptr )
        return nullptr;

    auto* left = root->left_;
    auto* right = root->right_;
    root->left_ = mirror(right);
    root->right_ = mirror(left);
    return root;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({8,6,5,-1,-1,7,-1,-1,10,9,-1,-1,11,-1,-1});
    auto* bt2 = init_btree({8,10,11,-1,-1,9,-1,-1,6,7,-1,-1,5,-1,-1});
    EXPECT_TRUE(compare(mirror(bt), bt2));
}
