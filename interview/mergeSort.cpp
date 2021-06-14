#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>


class MergeSort {
public:
    int* mergeSort(int* A, int n) {
        // write code here
        int tmp4Merge[n];
        mergeSort(A, tmp4Merge, 0, n);
        return A;
    }

private:
    void mergeSort(int* A, int* B, ssize_t begin, ssize_t end)
    {
        if ( end - begin <= 1 )
            return;

        ssize_t middle{(begin + end) / 2};
        mergeSort(A, B, begin, middle);
        mergeSort(A, B, middle, end);

        ssize_t leftIdx{begin}, rightIdx{middle}, mergeIdx{begin};
        for ( ; leftIdx < middle && rightIdx < end; ++mergeIdx ) {
            if ( A[leftIdx] <= A[rightIdx] )
                B[mergeIdx] = A[leftIdx++];
            else
                B[mergeIdx] = A[rightIdx++];
        }
        for ( ; leftIdx < middle; )
            B[mergeIdx++] = A[leftIdx++];
        for ( ; rightIdx < end; )
            B[mergeIdx++] = A[rightIdx++];
        for ( ssize_t idx{begin}; idx < end; ++idx )
            A[idx] = B[idx];
    }
};


TEST(TestShellSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    MergeSort{}.mergeSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    MergeSort{}.mergeSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

