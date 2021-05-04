#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

std::vector<int> bfs(TreeNode* root)
{
    std::vector<int> ret{};
    std::deque<TreeNode*> queue{};
    if ( root == nullptr )
        return ret;

    queue.emplace_back(root);
    for ( ; queue.size(); ) {
        auto* top = queue.front();
        queue.pop_front();
        ret.emplace_back(top->val_);
        if ( top->left_ != nullptr )
            queue.emplace_back(top->left_);
        if ( top->right_ != nullptr )
            queue.emplace_back(top->right_);
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,-1});
    std::vector<int> bfsSeq{1,2,5,3,4,6};
    EXPECT_EQ(bfs(bt), bfsSeq);
}
