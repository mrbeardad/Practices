#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

void tree_to_list(TreeNode* root, TreeNode*& tail)
{
    if ( root == nullptr )
        return;

    tree_to_list(root->left_, tail);
    tail->right_ = root;
    root->left_ = tail;
    tail = root;
    tree_to_list(root->right_, tail);
}

TreeNode* tree_to_list(TreeNode* root)
{
    TreeNode dummy{};
    TreeNode* tail = &dummy;
    tree_to_list(root, tail);
    if ( dummy.right_ != nullptr )
        dummy.right_->left_ = nullptr;
    return dummy.right_;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({4,2,1,-1,-1,3,-1,-1,5,-1,-1});
    TreeNode ls1{1}, ls2{2}, ls3{3}, ls4{4},ls5{5};
    ls1.right_ = &ls2;
    ls2.right_ = &ls3;
    ls3.right_ = &ls4;
    ls4.right_ = &ls5;
    ls2.left_ = &ls1;
    ls3.left_ = &ls2;
    ls4.left_ = &ls3;
    ls5.left_ = &ls4;

    auto* curLhs = tree_to_list(bt);
    auto* curRhs = &ls1;
    // 段错误也表示不匹配
    for ( ; curLhs != nullptr; ) {
        EXPECT_EQ(curLhs->val_, curRhs->val_);
        if ( curLhs->left_ != nullptr ) {
            EXPECT_EQ(curLhs->left_->val_, curRhs->left_->val_);
        }
        curLhs = curLhs->right_;
        curRhs = curRhs->right_;
    }
}
