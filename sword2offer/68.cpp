#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

/*************************************************************************************************/
// 前提条件：二叉搜索树
/*************************************************************************************************/
TreeNode* common_parent(TreeNode* lhs, TreeNode* rhs, TreeNode* root)
{
    if ( lhs == nullptr || rhs == nullptr )
        return nullptr;

    auto minAndMAx = std::minmax(lhs->val_, rhs->val_);
    for ( auto* curNode = root; curNode != nullptr; ) {
        if ( curNode->val_ >= minAndMAx.first && curNode->val_ <= minAndMAx.second )
            return curNode;
        else if ( curNode->val_ > minAndMAx.second )
            curNode = curNode->left_;
        else
            curNode = curNode->right_;
    }
    return nullptr;
}

/*************************************************************************************************/
// 前提条件：父节点指针
/*************************************************************************************************/
TreeNode* common_parent(TreeNode* lhs, TreeNode* rhs)
{
    if ( lhs == nullptr || rhs == nullptr )
        return nullptr;
    int leftCnt{}, rightCnt{};
    for ( auto* cur = lhs; cur != nullptr; cur = cur->parent_ )
        ++leftCnt;
    for ( auto* cur = rhs; cur != nullptr; cur = cur->parent_ )
        ++rightCnt;
    if ( leftCnt > rightCnt )
        for ( int step{leftCnt - rightCnt}; step > 0; --step )
            lhs = lhs->parent_;
    else
        for ( int step{rightCnt - leftCnt}; step > 0; --step )
            rhs = rhs->parent_;
    for ( ; lhs != rhs; lhs = lhs->parent_, rhs = rhs->parent_ );
    return lhs;
}

/*************************************************************************************************/
// 前提条件：普通树且无父节点指针
// @return:
//      TreeNode*   若inChildNum < 2则返回nullptr，若inChildNum == 2则返回公共祖先节点
//      inChildNum  表示以root为根的子树有多少个lhs和rhs
/*************************************************************************************************/
TreeNode* common_parent(TreeNode* lhs, TreeNode* rhs, TreeNode* root, int& inChildNum)
{
    if ( root == nullptr ) {
        return nullptr;
    }

    inChildNum = (lhs == root) + (rhs == root);
    if ( inChildNum == 2 ) {
        return root;
    }

    int inLeftChildNum{};
    auto* parent = common_parent(lhs, rhs, root->left_, inLeftChildNum);
    inChildNum += inLeftChildNum;
    if ( inChildNum == 2 ) {
        return parent == nullptr ? root : parent;
    }

    int inRightChildNum{};
    parent = common_parent(lhs, rhs, root->right_, inRightChildNum);
    inChildNum += inRightChildNum;
    if ( inChildNum == 2 ) {
        return parent == nullptr ? root : parent;
    }

    return nullptr;
}

/*************************************************************************************************/
// 保存路径
/*************************************************************************************************/
void search_path(TreeNode* lhs, TreeNode* rhs, TreeNode* root, std::vector<std::vector<TreeNode*> >& paths)
{
    if ( root == nullptr )
        return;

    paths.back().emplace_back(root);

    if ( lhs == root ) {
        if ( paths.size() == 1 ) {
            paths.emplace_back(paths.back());
        } else {
            paths.emplace_back();
            return;
        }
    }
    if ( rhs == root ) {
        if ( paths.size() == 1 ) {
            paths.emplace_back(paths.back());
        } else {
            paths.emplace_back();
            return;
        }
    }
    search_path(lhs, rhs, root->left_, paths);
    if ( paths.size() == 3 )
        return;
    search_path(lhs, rhs, root->right_, paths);
    if ( paths.size() == 3 )
        return;

    paths.back().pop_back();
}

TreeNode* common_parent_v4(TreeNode* lhs, TreeNode* rhs, TreeNode* root)
{
    if ( lhs == nullptr || rhs == nullptr || root == nullptr )
        return nullptr;
    std::vector<std::vector<TreeNode*> > paths(1);
    search_path(lhs, rhs, root, paths);
    auto [ignore, tagPos] = std::mismatch(paths[0].begin(), paths[0].end(), paths[1].begin());
    return *--tagPos;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({6,4,2,1,-1,-1,3,-1,-1,5,-1,-1,7,-1,-1});

    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->right_, bt)->val_, 6);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_->left_->left_, bt)->val_, 1);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_, bt)->val_, 4);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->right_, nullptr), nullptr);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, nullptr, bt), nullptr);
    EXPECT_EQ(common_parent(nullptr, bt->right_, bt), nullptr);

    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->right_)->val_, 6);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_->left_->left_)->val_, 1);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_)->val_, 4);
    EXPECT_EQ(common_parent(bt->left_->left_->left_, nullptr), nullptr);
    EXPECT_EQ(common_parent(nullptr, bt->right_), nullptr);

    int i{};
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->right_, bt, i)->val_, 6);
    i = 0;
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_->left_->left_, bt, i)->val_, 1);
    i = 0;
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->left_, bt, i)->val_, 4);
    i = 0;
    EXPECT_EQ(common_parent(bt->left_->left_->left_, bt->right_, nullptr, i), nullptr);
    i = 0;
    EXPECT_EQ(common_parent(bt->left_->left_->left_, nullptr, bt, i), nullptr);
    i = 0;
    EXPECT_EQ(common_parent(nullptr, bt->right_, bt, i), nullptr);

    EXPECT_EQ(common_parent_v4(bt->left_->left_->left_, bt->right_, bt)->val_, 6);
    EXPECT_EQ(common_parent_v4(bt->left_->left_->left_, bt->left_->left_->left_, bt)->val_, 1);
    EXPECT_EQ(common_parent_v4(bt->left_->left_->left_, bt->left_, bt)->val_, 4);
    EXPECT_EQ(common_parent_v4(bt->left_->left_->left_, bt->right_, nullptr), nullptr);
    EXPECT_EQ(common_parent_v4(bt->left_->left_->left_, nullptr, bt), nullptr);
    EXPECT_EQ(common_parent_v4(nullptr, bt->right_, bt), nullptr);
}
