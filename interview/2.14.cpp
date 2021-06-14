#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class Checker {
public:
    bool checkDuplicate(std::vector<int> A, int n) {
        // write code here
#if defined(SHELL_SORT)
        ssize_t gaps[]{1, 5, 19, 41, 109};
        for ( ssize_t curGap : gaps )
            for ( ssize_t idx{}; idx < n; ++idx )
                for ( ssize_t swapIdx{idx}; swapIdx >= curGap && A[swapIdx - curGap] > A[swapIdx]; swapIdx -= curGap )
                    std::swap(A.at(swapIdx), A.at(swapIdx - curGap));
        return std::adjacent_find(A.begin(), A.end()) != A.end();
#else
        for ( ssize_t last{n / 2 - 1}; last >= 0; --last )
            percolate_down(A.begin(), A.end(), A.begin() + last);
        for ( ssize_t right{n - 1}; right > 0; --right ) {
            std::swap(A.front(), A.at(right));
            percolate_down(A.begin(), A.begin() + right, A.begin());
        }
        return std::adjacent_find(A.begin(), A.end()) != A.end();
#endif // defined(SHELL_SORT)
    }

    template<typename RandomItr, typename Compare=std::less<decltype(*RandomItr{})> >
    void percolate_down(RandomItr begin, RandomItr end, RandomItr hole, Compare comp=std::less<decltype(*RandomItr{})>{})
    {
        auto holeVal = std::move(*hole);
        auto leftChild = [begin] (RandomItr root) {
            return (root - begin) * 2 + 1 + begin;
        };
        for ( ; leftChild(hole) < end; ) {
            auto child = leftChild(hole);
            child = child + 1 < end && comp(*child, *(child + 1)) ? child + 1 : child;
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
    std::vector<int> a{1, 3, 4, 33, 6, 1};
    EXPECT_EQ(Checker{}.checkDuplicate(a, a.size()), true);

    a.pop_back();
    EXPECT_EQ(Checker{}.checkDuplicate(a, a.size()), false);

    a.clear();
    EXPECT_EQ(Checker{}.checkDuplicate(a, a.size()), false);
}
