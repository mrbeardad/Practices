#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

void serialize(TreeNode* root, std::vector<int>& ser)
{
    if ( root == nullptr ) {
        ser.emplace_back(-1);
        return;
    }

    ser.emplace_back(root->val_);
    serialize(root->left_, ser);
    serialize(root->right_, ser);
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({10,5,4,-1,-1,7,-1,-1,12,-1,-1});
    std::vector<int> ser{}, tagSer{10,5,4,-1,-1,7,-1,-1,12,-1,-1};
    serialize(bt, ser);
    EXPECT_EQ(ser, tagSer);
}
