#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class ShellSort {
public:
    int* shellSort(int* A, int n) {
        // write code here
        std::array<ssize_t, 5> shellGaps{1, 5, 19, 41, 109};
        for ( ssize_t gap : shellGaps )
            for ( ssize_t idx{gap}; idx < n; ++idx )
                for ( ssize_t prev{idx}; prev >= gap && A[prev - gap] > A[prev]; prev -= gap )
                    std::swap(A[prev - gap], A[prev]);
        return A;
    }
};


TEST(TestShellSort, Test)
{
    std::vector<int> needSort{5, 1, 2, 3, 7, 9, 6, 4, 8};
    std::vector<int> sorted{1, 2, 3, 4, 5, 6, 7, 8, 9};

    ShellSort{}.shellSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);

    needSort.clear();
    sorted.clear();
    ShellSort{}.shellSort(needSort.data(), needSort.size());
    EXPECT_EQ(needSort, sorted);
}

