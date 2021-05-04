#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        // write code here
        ssize_t right{n + m - 1};
        ssize_t lastA{n - 1}, lastB{m - 1};
        for ( ; lastA >= 0 && lastB >= 0; --right ) {
            if ( A[lastA] > B[lastB] )
                A[right] = A[lastA--];
            else
                A[right] = B[lastB--];
        }
        for ( ; lastA >= 0; --right )
            A[right] = A[lastA--];
        for ( ; lastB >= 0; -- right )
            A[right] = B[lastB--];
        return A;
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<int> a{1, 2, 4 ,6}, b{3, 5, 7};
    a.resize(a.size() + b.size());
    std::vector<int> result{1, 2, 3, 4, 5, 6, 7};
    Merge{}.mergeAB(a.data(), b.data(), 4, 3);
    EXPECT_EQ(a, result);

    a.clear();
    b.clear();
    result.clear();
    Merge{}.mergeAB(a.data(), b.data(), 0, 0);
    EXPECT_EQ(a, result);

}
