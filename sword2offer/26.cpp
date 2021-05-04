#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

bool isSubTree(TreeNode* main, TreeNode* sub)
{
    if ( sub == nullptr )
        return true;
    if ( main == nullptr )
        return false;
    if ( main->val_ != sub->val_ )
        return false;
    return isSubTree(main->left_, sub->left_) && isSubTree(main->right_, sub->right_);
}

bool hasSubTree(TreeNode* main, TreeNode* sub)
{
    if ( main == nullptr )
        return false;

    if ( isSubTree(main, sub) )
        return true;
    if ( hasSubTree(main->left_, sub) )
        return true;
    if ( hasSubTree(main->right_, sub) )
        return true;
    return false;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({8,8,9,-1,-1,2,4,-1,-1,7,-1,-1,7,-1,-1});
    auto* sub = init_btree({8,9,-1,-1,2,-1,-1});
    EXPECT_TRUE(hasSubTree(bt, sub));
    EXPECT_FALSE(hasSubTree(sub, bt));
    EXPECT_TRUE(hasSubTree(bt, nullptr));
    EXPECT_FALSE(hasSubTree(nullptr, sub));
}
