#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


struct Node
{
    int     val_;
    Node*   parent_;
    Node*   left_;
    Node*   right_;
};


class Solution
{
public:
    // 中序遍历
    Node* next_node(Node* curNode)
    {
        if ( curNode == nullptr )
            return nullptr;
        if ( curNode->right_ != nullptr ) {
            for ( curNode = curNode->right_; curNode->left_ != nullptr; curNode = curNode->left_ );
            return curNode;
        } else {
            for ( ; curNode->parent_ != nullptr && curNode->parent_->left_ != curNode; curNode = curNode->parent_ );
            return curNode->parent_;
        }
    }
};


class TestNode : public testing::Test
{
protected:
    Node* bt_;

    TestNode()
    {
        bt_ = new Node{0};
        bt_->left_ = new Node{1, bt_};
        bt_->right_ = new Node{2, bt_};
    }

    ~TestNode()
    {
        delete bt_->left_;
        delete bt_->right_;
        delete bt_;
    }
};


TEST_F(TestNode, TestCase)
{
    EXPECT_EQ(Solution{}.next_node(bt_)->val_, bt_->right_->val_);
    EXPECT_EQ(Solution{}.next_node(bt_->left_)->val_, bt_->val_);
    EXPECT_EQ(Solution{}.next_node(bt_->right_), nullptr);
}
