#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

struct ListNode
{
    int         val_;
    ListNode*   next_;
};

ListNode* del_list(ListNode* head, ListNode* del)
{
    if ( del == nullptr || head == nullptr )
        return nullptr;
    ListNode dummyNode{0, head};
    if ( del->next_ == nullptr ) {
        auto* prevNode = &dummyNode;
        auto* curNode = head;
        for ( ; curNode != nullptr && curNode->next_ != nullptr; ) {
            prevNode = curNode;
            curNode = curNode->next_;
        }
        prevNode->next_ = nullptr;
        delete curNode;
        return dummyNode.next_;
    } else {
        auto* next = del->next_;
        *del = *del->next_;
        delete next;
        return dummyNode.next_;
    }
}

int main()
{
    auto print = [] (ListNode* ls) {
        for ( ; ls != nullptr; ls = ls->next_ ) {
            std::cout << ls->val_ << ',';
        }
        std::cout << std::endl;
    };
    auto* ls = new ListNode{0, new ListNode{1, new ListNode{2, nullptr}}};
    print(del_list(ls, ls->next_));
    print(del_list(ls, ls->next_));
    print(del_list(ls, ls->next_));
    print(del_list(ls, ls->next_));
}
