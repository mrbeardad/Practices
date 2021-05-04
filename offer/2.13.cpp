#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class ScaleSort {
public:
    std::vector<int>& sortElement(std::vector<int>& A, int n, int k) {
        // write code here
        std::vector<int> heap{A.begin(), A.begin() + k + 1};
        std::make_heap(heap.begin(), heap.end(), std::greater<int>{});
        ssize_t idx{};
        for ( ; idx + k + 1 < n; ++idx ) {
            A.at(idx) = heap.front();
            heap.front() = A.at(idx + k + 1);
            percolate_down(heap.begin(), heap.end(), heap.begin(), std::greater<int>{});
        }
        for ( ; idx < n; ++idx ) {
            A.at(idx) = heap.front();
            heap.front() = heap.back();
            heap.pop_back();
            percolate_down(heap.begin(), heap.end(), heap.begin(), std::greater<int>{});
        }

        return A;
    }

    template<typename RandomItr, typename Compare=std::less<decltype(*RandomItr{})>>
    void percolate_down(RandomItr begin, RandomItr end, RandomItr hole, Compare comp=std::less<decltype(*RandomItr{})>{})
    {
        auto holeVal = std::move(*hole);
        auto leftChild = [begin] (RandomItr root) {
            return (root - begin) * 2 + 1 + begin;
        };
        for ( ; leftChild(hole) < end; ) {
            auto child = leftChild(hole);
            child = child + 1 < end && comp(*(child), *(child + 1)) ? child + 1 : child;
            if ( comp(holeVal, *child) )
                *hole = *child;
            else
                break;
            hole = child;
        }
        *hole = holeVal;
    }
};

TEST(TestSuit, TestCase)
{
    std::vector<int> neadHeapDown{2, 4, 3, 2};
    std::vector<int> heaped{4, 2, 3, 2};
    ScaleSort{}.percolate_down(neadHeapDown.begin(), neadHeapDown.end(), neadHeapDown.begin());
    EXPECT_EQ(neadHeapDown, heaped);

    std::vector<int> needSort{2, 1, 4, 3, 5, 6};
    std::vector<int> soeted{1, 2, 3, 4, 5, 6};
    ScaleSort{}.sortElement(needSort, needSort.size(), 2);
    EXPECT_EQ(needSort, soeted);
}
