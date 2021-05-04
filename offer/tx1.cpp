#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


struct ListNode {
   int val;
   struct ListNode *next;
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* solve(ListNode* head) {
        // write code here
        if ( head == nullptr )
            return nullptr;
        ListNode dummyNode{0, head};
        auto* tail = head;
        int min = std::numeric_limits<int>::max();
        for ( auto* curNode = head; curNode != nullptr; ) {
            min = std::min(min, curNode->val);
            tail = curNode;
            curNode = curNode->next;
        }
        std::vector<std::pair<ListNode*, ListNode*> > heads{};
        for ( auto* curNode = head, *prevNode = &dummyNode; curNode != nullptr; ) {
            if ( curNode->val == min ) {
                auto* next = curNode->next == nullptr ? head : curNode->next;
                heads.emplace_back(std::make_pair(prevNode, next));
            }
            prevNode = curNode;
            curNode = curNode->next;
        }
        for ( ; heads.size() > 1; ) {
            min = std::numeric_limits<int>::max();
            for ( size_t idx{}; idx < heads.size(); ++idx ) {
                min = std::min(min, heads[idx].second->val);
            }
            auto newEnd = std::remove_if(heads.begin(), heads.end(), [min](std::pair<ListNode*, ListNode*>& elem){
                    return elem.second->val != min;
                    });
            heads.erase(newEnd, heads.end());
            std::for_each(heads.begin(), heads.end(), [head](std::pair<ListNode*, ListNode*>& elem){
                    elem.second = elem.second->next == nullptr ? head : elem.second->next;
                    });
        }
        // std::cout << "\e[31mfuck:\e[m " << heads[0].first->next->val << ',' << heads[0].second->val << std::endl;
        dummyNode.next = heads[0].first->next;
        tail->next = head;
        heads[0].first->next = nullptr;
        return dummyNode.next;
    }
};


int main()
{
    ListNode* ls = new ListNode{2, new ListNode{2, new ListNode{5, new ListNode{2, new ListNode{2, nullptr}}}}};
    
    for ( auto* curNode = Solution{}.solve(ls); curNode != nullptr; curNode = curNode->next )
        std::cout << curNode->val << ',';

    return 0;
}

