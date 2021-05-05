#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "simple_btree.hpp"

using Paths = std::vector<std::vector<int> >;

void find_path(TreeNode* root, int key, Paths& paths)
{
    if ( root == nullptr )
        return;

    paths.back().emplace_back(root->val_);

    if ( root->left_ == nullptr && root->right_ == nullptr ) {
        if ( key == root->val_ )
            paths.emplace_back(paths.back());
        paths.back().pop_back();
        return;
    }

    find_path(root->left_, key - root->val_, paths);
    find_path(root->right_, key - root->val_, paths);
    paths.back().pop_back();
}

bool find_one_path(TreeNode* root, int key, std::vector<int>& onepath)
{
    if ( root == nullptr && key == 0 )
        return true;
    if ( root == nullptr || key == 0 )
        return false;

    onepath.emplace_back(root->val_);
    if ( find_one_path(root->left_, key - root->val_, onepath)
            || find_one_path(root->right_, key - root->val_, onepath) )
        return true;
    onepath.pop_back();
    return false;
}

TEST(TestSuit, TestCase)
{
    auto* bt = init_btree({10,5,4,-1,-1,7,-1,-1,12,-1,-1});
    Paths paths(1), tagPaths{{10,5,7},{10,12},{}};
    find_path(bt, 22, paths);
    EXPECT_EQ(paths, tagPaths);

    std::vector<int> path{}, tagPath{10,5,7};
    find_one_path(bt, 22, path);
    EXPECT_EQ(path, tagPath);
}
