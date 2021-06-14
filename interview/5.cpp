#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>

struct ListNode
{
    int value_;
    ListNode* prev_;
    ListNode* next_;
};

class LRUCache
{
    // key, (val, cnt)
    std::unordered_map<int, ListNode*> map_;
    int maxSize_;
public:
    LRUCache(int cap) : maxSize_{cap} {  }

    int get(int key)
    {
        auto tagItr = map_.find(key);
        if ( tagItr != map_.end() ) {
            ++tagItr->second.second;
            return tagItr->second.first;
        } else {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if ( map_.size() >= maxSize_ ) {
            auto tagItr = std::max_element(map_.begin(), map_.end(),
                    [](std::pair<int, std::pair<int, int> >& lhs, std::pair<int, std::pair<int, int> >& rhs){
                        return lhs.second.second < rhs.second.second;
                    });
            if ( tagItr != map_.end() ) {
                map_.erase(tagItr);
            }
        }
        map_.emplace(std::pair<int, std::pair<int, int> >{key, std::pair<int, int>{value, 0}});
    }
};

int main()
{
    

    return 0;
}

