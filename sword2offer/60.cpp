#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<double> probability(int dictCount)
{
    if ( dictCount < 1 )
        return {};

    std::vector<int> appearCount[2]{};
    appearCount[0].resize(dictCount * 6 + 1);
    appearCount[1].resize(dictCount * 6 + 1, 1);
    // 骰子数
    for ( int curDictCount{2}; curDictCount <= dictCount; ++curDictCount ) {
        auto& curDp = appearCount[curDictCount % 2];
        auto& prevDp = appearCount[1 - curDictCount % 2];
        // 点数大小
        for ( int curNum{curDictCount}; curNum <= curDictCount * 6; ++curNum ) {
            curDp[curNum] = 0;
            // 点数出现次数，依赖上次骰子数的点数大小
            for ( int prevNum{std::min(curNum - 1, (curDictCount - 1) * 6)}, prevNumEage{std::max(curDictCount - 1, curNum - 6)};
                    prevNum >= prevNumEage; --prevNum ) {
                curDp[curNum] += prevDp[prevNum];
            }
        }
    }
    auto& dp = appearCount[dictCount % 2];
    std::vector<double> probabilities(dictCount * 6 + 1);
    double totle{std::pow(6.0, dictCount)};
    std::transform(dp.begin(), dp.end(), probabilities.begin(), [dictCount, totle] (int val) {
        return val / totle;
    });
    probabilities.erase(probabilities.begin(), probabilities.begin() + dictCount);
    return probabilities;
}

TEST(TestSuit, TestCase)
{
    std::cout << testing::PrintToString(probability(1)) << std::endl;
    std::cout << testing::PrintToString(probability(2)) << std::endl;
    std::cout << testing::PrintToString(probability(3)) << std::endl;
    std::cout << testing::PrintToString(probability(4)) << std::endl;
}
