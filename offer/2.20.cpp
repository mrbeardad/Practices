#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Gap {
public:
    int maxGap(std::vector<int> A, int n) {
        // write code here
        auto minmax = std::minmax_element(A.begin(), A.end());
        int min{*minmax.first}, max{*minmax.second};
        auto bktidx = [min, max, n] (int num) {
            return num == max ? n : static_cast<ssize_t>((num - min) / ((max - min) / static_cast<float>(n)));
        };
        std::vector<std::vector<int> > buckets(n + 1);
        for ( int num : A ) {
            buckets.at(bktidx(num)).emplace_back(num);
        }
        int maxGap{};
        for ( ssize_t idx{}; idx < buckets.size(); ++idx ) {
            if ( buckets.at(idx).empty() )
                continue;
            ssize_t nextIdx{idx + 1};
            for ( ; nextIdx < buckets.size() && buckets.at(nextIdx).empty(); ++nextIdx );
            if ( nextIdx >= buckets.size() )
                break;
            maxGap = std::max(maxGap,
                    *std::min_element(buckets.at(nextIdx).begin(), buckets.at(nextIdx).end())
                    - *std::max_element(buckets.at(idx).begin(), buckets.at(idx).end()));
        }
        return maxGap;
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<int> v{1, 4, 6, 2, 7};
    EXPECT_EQ(Gap{}.maxGap(v, v.size()), 2);
}
