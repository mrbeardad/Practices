#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <vector>

class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for ( ssize_t right{n - 1}; right > 0; --right )
            for ( ssize_t idx{}; idx < right; ++idx )
                if ( A[idx] > A[idx + 1] )
                    std::swap(A[idx], A[idx + 1]);
        return A;
    }
};

TEST(TestBubbleSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    BubbleSort{}.bubbleSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    BubbleSort{}.bubbleSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}
