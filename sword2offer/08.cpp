#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include <simple_btree.hpp>

/*************************************************************************************************/
// 中序遍历的下个节点
/*************************************************************************************************/
TreeNode* getnext(TreeNode* curNode)
{
    if ( curNode == nullptr )
        return nullptr;
    if ( curNode->right_ != nullptr ) {
        curNode = curNode->right_;
        for ( ; curNode->left_ != nullptr; curNode = curNode->left_ );
        return curNode;
    } else {
        for ( ; curNode->parent_ != nullptr && curNode->parent_->left_ != curNode; )
            curNode = curNode->parent_;
        return curNode->parent_;
    }
}


TEST(TestSuit, TestCase)
{
    TreeNode bt1{1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};

    EXPECT_EQ(getnext(bt1.left_->left_)->val_,          bt1.left_->val_);
    EXPECT_EQ(getnext(bt1.left_->right_->right_)->val_, bt1.val_);
    EXPECT_EQ(getnext(bt1.right_->left_)->val_,         bt1.right_->val_);
    EXPECT_EQ((void*)getnext(bt1.right_->right_),       (void*)nullptr);
}
