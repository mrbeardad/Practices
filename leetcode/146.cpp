#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    list<int> queue_;
    unordered_map<int, list<int>::iterator> posInQueue_;
    size_t maxSize_;
public:
    explicit LRUCache(size_t capacity)
        : queue_{}, posInQueue_{}, maxSize_{capacity} {  }

    int get(int key) {
        auto p2KeyAndPos = posInQueue_.find(key);
        if ( p2KeyAndPos == posInQueue_.end() )
            return -1;
        auto tagPos = p2KeyAndPos->second;
        if ( tagPos != queue_.begin() ) {
            queue_.splice(queue_.begin(), queue_, tagPos, next(tagPos));
        }
        return *tagPos;
    }

    void put(int key, int value) {
        if ( queue_.size() == maxSize_ )
            queue_.pop_front();
        auto p2KeyAndPos = posInQueue_.find(key);
        if ( p2KeyAndPos == posInQueue_.end() )
            queue_.emplace_back(value);
        else
            *p2KeyAndPos->second = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
