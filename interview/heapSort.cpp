#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class HeapSort {
public:
    int* heapSort(int* A, int n) {
        for ( ssize_t idx{n / 2 - 1}; idx >= 0; --idx )
            percolate_down(A, n, idx);

        for ( ssize_t right{n - 1}; right > 0; --right ) {
            std::swap(A[0], A[right]);
            percolate_down(A, right, 0);
        }
        return A;
    }

private:
    void percolate_down(int* A, ssize_t n, ssize_t root)
    {
        int holeVal{A[root]};
        auto leftChild = [] (ssize_t rootIdx) {
            return rootIdx * 2 + 1;
        };

        for ( ; leftChild(root) < n; ) {
            ssize_t child{leftChild(root)};
            if ( child + 1 < n && A[child + 1] > A[child] )
                ++child;
            if ( A[child] > holeVal )
                A[root] = A[child];
            else
                break;
            root = child;
        }
        A[root] = holeVal;
    }
};


TEST(TestShellSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    HeapSort{}.heapSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.assign({1});
    sorted.assign({1});
    HeapSort{}.heapSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.assign({2, 1});
    sorted.assign({1, 2});
    HeapSort{}.heapSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    HeapSort{}.heapSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

