#ifndef SIMPLE_LIST
#define SIMPLE_LIST

#include <utility>

struct ListNode
{
    int         val_;
    ListNode*   next_;
};

ListNode* init_list(const std::initializer_list<int>& il)
{
    ListNode dummy{};
    auto* tail = &dummy;
    for ( int elem : il ) {
        tail->next_ = new ListNode{elem, nullptr};
        tail = tail->next_;
    }
    return dummy.next_;
}

int compare(ListNode* lhs, ListNode* rhs)
{
    for ( ; lhs != nullptr && rhs != nullptr; ) {
        if ( lhs->val_ < rhs->val_ )
            return -1;
        else if ( rhs->val_ < lhs->val_ )
            return 1;
        lhs = lhs->next_;
        rhs = rhs->next_;
    }
    if ( lhs == rhs )
        return 0;
    else if ( lhs == nullptr )
        return -1;
    else
        return 1;
}

#endif // SIMPLE_LIST
