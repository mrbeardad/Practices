#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

bool le(std::pair<int, int> lhs, std::pair<int, int> rhs)
{
    if ( lhs.first == rhs.first )
        return lhs.second < rhs.second;
    return lhs.first > rhs.first;   // heap算法默认建立最大堆
}

int main()
{
    std::vector<int> hots(1001);
    std::vector<std::pair<int, int> > heap10{};
    int lines{};
    std::cin >> lines;
    std::string op{};
    while ( std::cin >> op ) {
        if ( op[0] == 'q' ) {
            if ( heap10.empty() )
                std::cout << "null\n";
            else {
                // for ( auto& thisPair : heap10 ) {
                //     std::cout << thisPair.first << ',' << thisPair.second << ' ';
                // } std::cout << std::endl;
                auto heapSort = heap10;
                for ( auto end = heapSort.end(); end != heapSort.begin(); --end ) {
                    std::pop_heap(heapSort.begin(), end, le);
                }
                std::cout << heapSort[0].second;
                for ( size_t idx{1}; idx < heapSort.size(); ++idx ) {
                    std::cout << ' ' << heapSort[idx].second;
                }
                std::cout << '\n';
            }
        } else {
            int id, hotVal;
            std::cin >> id >> hotVal;
            // 如果消息已在堆中，修改值并重建堆
            auto itr = std::find(heap10.begin(), heap10.end(), std::make_pair(hots[id], id));
            if ( itr != heap10.end() ) {
                itr->first += hotVal;
                std::make_heap(heap10.begin(), heap10.end(), le);
            // 没在堆中且堆size < 10
            } else if ( heap10.size() < 10 ) {
                heap10.emplace_back(std::make_pair(hots[id] + hotVal, id));
                std::push_heap(heap10.begin(), heap10.end(), le);
            // 没在堆中且需要新插入堆中
            } else if ( hots[id] + hotVal > heap10[0].first 
                    || hots[id] + hotVal == heap10[0].first && id < heap10[0].second ) {
                heap10[0] = std::make_pair(hots[id] + hotVal, id);
                std::make_heap(heap10.begin(), heap10.end(), le);
            }
            hots[id] += hotVal;
        }
    }

    return 0;
}

