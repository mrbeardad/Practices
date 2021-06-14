#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>


class QuickSort {
public:
    int* quickSort(int* A, int n) {
        // write code here
        quickSort(A, 0, n);
        return A;
    }

private:
    void quickSort(int* A, ssize_t begin, ssize_t end)
    {
        // if ( end - begin <= 1 )
        //     return;
        // 小数组使用插入排序优化
        if ( end - begin <= 10 ) {
            for ( ssize_t idx{begin + 1}; idx < end; ++idx )
                for ( ssize_t swapIdx{idx}; swapIdx > 0 && A[swapIdx - 1] > A[swapIdx]; --swapIdx )
                    std::swap(A[swapIdx - 1], A[swapIdx]);
            return;
        }

        ssize_t middle{(begin + end) / 2}, last{end - 1};
        if ( A[middle] < A[begin] )
            std::swap(A[middle], A[begin]);
        if ( A[last] < A[begin] )
            std::swap(A[last], A[begin]);
        if ( A[middle] < A[last] )
            std::swap(A[middle], A[last]);
        int& pivot{A[last]};

        ssize_t left{begin}, right{last};
        for ( ; ; ) {
            // 有[begin] <= pivot 与 [last] == pivot作边界，不可能越界
            for ( ; A[++left] < pivot; );
            for ( ; A[--right] > pivot; );
            if ( left <= right )
                std::swap(A[left], A[right]);
            else
                break;
        }
        std::swap(A[left], pivot);

        quickSort(A, begin, left);
        quickSort(A, left + 1, end);
    }
};



TEST(TestShellSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    QuickSort{}.quickSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.assign({1});
    sorted.assign({1});
    QuickSort{}.quickSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.assign({2, 1});
    sorted.assign({1, 2});
    QuickSort{}.quickSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    QuickSort{}.quickSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

