#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for ( ssize_t right{n - 1}; right > 0; --right ) {
            int maxIdx{};
            for ( ssize_t idx{1}; idx <= right; ++idx )
                maxIdx = A[idx] > A[maxIdx] ? idx : maxIdx;
            std::swap(A[maxIdx], A[right]);
        }
        return A;
    }
};


TEST(TestSelectSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    SelectionSort{}.selectionSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    SelectionSort{}.selectionSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

