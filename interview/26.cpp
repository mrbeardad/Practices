#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    bool comp(TreeNode* A, TreeNode* B)
    {
        if ( A == nullptr && B == nullptr )
            return true;
        else if ( A == nullptr || B == nullptr || A->val != B->val )
            return false;
        else
            return comp(A->left, B->left) && comp(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if ( A == nullptr || B == nullptr )
            return false;
        std::deque<TreeNode*> queue{A};
        while ( queue.size() ) {
            if ( queue.front()->val == B->val
                    && (comp(queue.front(), B)) )
                return true;
            auto* left = queue.front()->left;
            auto* right = queue.front()->right;
            if ( left != nullptr )
                queue.emplace_back(left);
            if ( right != nullptr )
                queue.emplace_back(right);
            queue.pop_front();
        }
        return false;
    }
};

TEST(TestSuit, TestCase)
{
    auto* tree1 = new TreeNode{10};
    auto* tree2 = new TreeNode{12};
    auto* tree3 = new TreeNode{6};
    auto* tree4 = new TreeNode{8};
    auto* tree5 = new TreeNode{3};
    auto* tree6 = new TreeNode{11};
}
