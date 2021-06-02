#ifndef SIMPLE_BTREE
#define SIMPLE_BTREE

#include <ostream>
#include <utility>

struct TreeNode
{
    TreeNode*   left_;
    TreeNode*   right_;
    TreeNode*   parent_;
    int         val_;

    TreeNode(int val=0)
        : left_{}, right_{}, parent_{}, val_{val} {  }
};

template<typename Itr>
TreeNode* init_btree(Itr& begin, Itr end)
{
    if ( begin == end )
        return nullptr;

    if ( *begin == -1 ) {
        ++begin;
        return nullptr;
    }

    auto* root = new TreeNode{*begin++};
    root->left_ = init_btree(begin, end);
    if ( root->left_ != nullptr )
        root->left_->parent_ = root;
    root->right_ = init_btree(begin, end);
    if ( root->right_ != nullptr )
        root->right_->parent_ = root;
    return root;
}

TreeNode* init_btree(const std::initializer_list<int>& il)
{
    auto begin = il.begin();
    return init_btree(begin, il.end());
}

bool compare(const TreeNode* lhs, const TreeNode* rhs)
{
    if ( lhs == nullptr && rhs == nullptr )
        return true;
    if ( lhs == nullptr || rhs == nullptr )
        return false;

    return lhs->val_ == rhs->val_
        && compare(lhs->left_, rhs->left_) && compare(lhs->right_, rhs->right_);
}

std::ostream& operator<<(std::ostream& output, const TreeNode* bt)
{
    if ( bt == nullptr ) {
        output << -1 << ',';
        return output;
    }
    output << bt->val_ << ',';
    output << bt->left_;
    output << bt->right_;
    return output;
}

#endif // SIMPLE_BTREE
