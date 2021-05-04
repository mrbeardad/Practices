#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

TreeNode* find_kth_recur(TreeNode* root, int& kth)
{
    if ( root == nullptr )
        return nullptr;

    auto* leftResult = find_kth_recur(root->left_, kth);
    if ( leftResult != nullptr )
        return leftResult;

    if ( --kth == 0 )
        return root;

    auto* rightResult = find_kth_recur(root->right_, kth);
    if ( rightResult != nullptr )
        return rightResult;

    return nullptr;
}

TreeNode* find_kth(TreeNode* root, int kth)
{
    if ( kth <= 0 )
        return nullptr;
    return find_kth_recur(root, kth);
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({5,3,2,-1,-1,4,-1,-1,7,6,-1,-1,8,-1,-1});
    EXPECT_EQ(find_kth(bt, 0), nullptr);
    EXPECT_EQ(find_kth(bt, 1)->val_, 2);
    EXPECT_EQ(find_kth(bt, 2)->val_, 3);
    EXPECT_EQ(find_kth(bt, 3)->val_, 4);
    EXPECT_EQ(find_kth(bt, 4)->val_, 5);
    EXPECT_EQ(find_kth(bt, 5)->val_, 6);
    EXPECT_EQ(find_kth(bt, 6)->val_, 7);
    EXPECT_EQ(find_kth(bt, 7)->val_, 8);
    EXPECT_EQ(find_kth(bt, 8), nullptr);
    EXPECT_EQ(find_kth(nullptr, 1), nullptr);
}
