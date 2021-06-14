#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x)
        : val{x}, left{NULL}, right{NULL} {  }
};

class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        // write code here
        std::vector<int> seqA{}, seqB{};
        serialize(seqA, A);
        serialize(seqB, B);
        return std::search(seqA.begin(), seqA.end(), seqB.begin(), seqB.end()) != seqA.end();
    }

    void serialize(std::vector<int>& vec, TreeNode* root)
    {
        if ( root == nullptr ) {
            vec.emplace_back(std::numeric_limits<int>::min());
            return;
        }

        vec.emplace_back(root->val);
        serialize(vec, root->left);
        serialize(vec, root->right);
    }
};


TEST(TestSuit, TestCase)
{
    
}
