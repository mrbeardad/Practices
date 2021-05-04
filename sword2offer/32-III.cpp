#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

std::vector<int> bfs(TreeNode* root)
{
    std::vector<int> ret{};
    if ( root == nullptr )
        return ret;
    std::vector<TreeNode*> stack[2]{};
    ssize_t whichStack{};
    stack[whichStack].emplace_back(root);
    for ( ; stack[whichStack].size(); ) {
        auto* top = stack[whichStack].back();
        stack[whichStack].pop_back();
        ret.emplace_back(top->val_);
        if ( whichStack == 0 ) {
            if ( top->left_ != nullptr )
                stack[1 - whichStack].emplace_back(top->left_);
            if ( top->right_ != nullptr )
                stack[1 - whichStack].emplace_back(top->right_);
        } else {
            if ( top->right_ != nullptr )
                stack[1 - whichStack].emplace_back(top->right_);
            if ( top->left_ != nullptr )
                stack[1 - whichStack].emplace_back(top->left_);
        }
        if ( stack[whichStack].empty() ) {
            ret.emplace_back(-1);
            whichStack = 1 - whichStack;
        }
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,-1});
    std::vector<int> bfsSeq{1,-1,5,2,-1,3,4,6,-1};
    EXPECT_EQ(bfs(bt), bfsSeq);
}
