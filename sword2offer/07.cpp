#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include <simple_btree.hpp>

/*************************************************************************************************/
// 根据前序遍历序列与中序遍历序列构建二叉树
/*************************************************************************************************/
using Itr = std::vector<int>::const_iterator;
TreeNode* build(Itr preBegin, Itr preEnd, Itr postBegin, Itr postEnd)
{
    if ( preBegin == preEnd || postBegin == postEnd )
        return nullptr;
    auto* root = new TreeNode(*preBegin);
    auto postMid = std::find(postBegin, postEnd, *preBegin);
    auto preMid = preBegin + 1 + (postMid - postBegin);
    root->left_ = build(preBegin + 1, preMid, postBegin, postMid);
    root->right_ = build(preMid, preEnd, postMid + 1, postEnd);
    return root;
}

TEST(TestSuit, TestCase)
{
    TreeNode bt1{1,2,4,-1,7,-1,-1,-1,3,5,-1,-1,6,8,-1,-1,-1};
    std::vector<int> pre{1,2,4,7,3,5,6,8}, post{4,7,2,1,5,3,8,6};
    auto* bt2 = build(pre.begin(), pre.end(), post.begin(), post.end());
    EXPECT_EQ(bt1, *bt2);
}
