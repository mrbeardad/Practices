#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>


class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for ( ssize_t idx{1}; idx < n; ++idx ) {
            int needInsert{A[idx]};
            ssize_t istIdx{idx};
            for ( ; istIdx >= 1 && A[istIdx - 1] > needInsert; --istIdx )
                A[istIdx] = A[istIdx - 1];
            A[istIdx] = needInsert;
        }
        return A;
    }
};


TEST(TestInsertSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    InsertionSort{}.insertionSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    InsertionSort{}.insertionSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

