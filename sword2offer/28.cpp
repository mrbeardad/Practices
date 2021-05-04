#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

bool is_semmetrical(TreeNode* lhs, TreeNode* rhs)
{
    if ( lhs == nullptr && rhs == nullptr )
        return true;
    if ( lhs == nullptr || rhs == nullptr )
        return false;
    return lhs->val_ == rhs->val_
        && is_semmetrical(lhs->left_, rhs->right_) && is_semmetrical(lhs->right_, rhs->left_);
}

bool is_semmetrical(TreeNode* root)
{
    if ( root == nullptr )
        return false;
    return is_semmetrical(root->left_, root->right_);
}

TEST(TestSuit, TestCase)
{
    EXPECT_TRUE(is_semmetrical(init_btree({8,6,5,-1,-1,7,-1,-1,6,7,-1,-1,5,-1,-1})));
    EXPECT_FALSE(is_semmetrical(init_btree({8,6,5,-1,-1,7,-1,-1,6,5,-1,-1,7,-1,-1})));
    EXPECT_FALSE(is_semmetrical(init_btree({7,7,7,-1,-1,7,-1,-1,7,7,-1,-1,-1})));
}
