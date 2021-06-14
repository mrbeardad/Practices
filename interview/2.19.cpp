#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Subsequence {
public:
    int shortestSubsequence(std::vector<int> A, int n) {
        // write code here
        std::vector<ssize_t> monoStk{};
        for ( ssize_t idx{}; idx < n; ++idx ) {
            for ( ; monoStk.size() && A.at(monoStk.back()) > A.at(idx); )
                monoStk.pop_back();
            monoStk.emplace_back(idx);
        }
        ssize_t left{};
        for ( ; left < monoStk.size() && left == monoStk.at(left); ++left );

        monoStk.clear();
        for ( ssize_t idx{static_cast<ssize_t>(A.size()) - 1}; idx >= 0 ; --idx ) {
            for ( ; monoStk.size() && A.at(monoStk.back()) < A.at(idx); )
                monoStk.pop_back();
            monoStk.emplace_back(idx);
        }
        ssize_t right{static_cast<ssize_t>(A.size()) - 1};
        for ( ssize_t idx{}; right >= 0 && monoStk.at(idx) == right; --right, ++idx );
        return std::max(right - left + 1, 0L);
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<int> a{1,2,5,4,3,6};
    EXPECT_EQ(Subsequence{}.shortestSubsequence(a, a.size()), 3);
    a.pop_back();
    EXPECT_EQ(Subsequence{}.shortestSubsequence(a, a.size()), 3);
}
