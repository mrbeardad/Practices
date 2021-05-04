#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>

struct LintNode
{
    LintNode*   next_;
    LintNode*   sibling_;
    int         val_;

    LintNode(int val=0)
        : next_{}, sibling_{}, val_{val} {  }
};

// 用树模拟复杂链表
LintNode* copy_complex_list(LintNode* head)
{
    std::unordered_map<LintNode*, LintNode*> origAndCopy{};
    LintNode dummy{};
    auto* tail = &dummy;
    for ( auto* cur = head; cur != nullptr; cur = cur->next_ ) {
        if ( origAndCopy[cur] == nullptr ) {
            tail->next_ = new LintNode{cur->val_};
            origAndCopy[cur] = tail->next_;
        } else {
            tail->next_ = origAndCopy[cur];
        }
        tail = tail->next_;
        if ( cur->sibling_ != nullptr ) {
            if ( origAndCopy[cur->sibling_] == nullptr ) {
                tail->sibling_ = new LintNode{cur->sibling_->val_};
                origAndCopy[cur->sibling_] = tail->sibling_;
            } else {
                tail->sibling_ = origAndCopy[cur->sibling_];
            }
        }
    }
    return dummy.next_;
}

TEST(TestSuit, TestCase)
{
    LintNode l1{1}, l2{2}, l3{3}, l4{4}, l5{5};
    l1.next_ = &l2; l1.sibling_ = &l3;
    l2.next_ = &l3; l2.sibling_ = &l5;
    l3.next_ = &l4;
    l4.next_ = &l5; l4.sibling_ = &l2;

    auto* oldLs = &l1;
    auto* newLs = copy_complex_list(&l1);
    EXPECT_EQ(newLs->val_, oldLs->val_);
    EXPECT_EQ(newLs->next_->val_, oldLs->next_->val_);
    EXPECT_EQ(newLs->next_->next_->val_, oldLs->next_->next_->val_);
    EXPECT_EQ(newLs->next_->next_->next_->val_, oldLs->next_->next_->next_->val_);
    EXPECT_EQ(newLs->next_->next_->next_->next_->val_, oldLs->next_->next_->next_->next_->val_);
    EXPECT_EQ(newLs->sibling_->val_, oldLs->sibling_->val_);
    EXPECT_EQ(newLs->next_->sibling_->val_, oldLs->next_->sibling_->val_);
    EXPECT_EQ(newLs->next_->next_->next_->sibling_->val_, oldLs->next_->next_->next_->sibling_->val_);
}
