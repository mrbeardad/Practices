#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        quick_sort(nums.begin(), nums.end());
        return nums;
    }

private:
    template<typename RandomItr, typename Comp=std::less<typename RandomItr::value_type> >
    void quick_sort(RandomItr begin, RandomItr end, Comp comp=std::less<typename RandomItr::value_type>{})
    {
        // 小数组用插入排序
        if ( end - begin <= 10 ) {
            for ( auto pos = begin + 1; pos < end; ++pos )
                for ( auto istPos = pos; istPos > begin && comp(*istPos, *(istPos - 1)); --istPos )
                    std::swap(*(istPos - 1), *istPos);
            return;
        }

        // 选取枢纽元
        auto mid = begin + (end - begin) / 2, right = end - 1;
        if ( comp(*mid, *begin) )
            std::swap(*mid, *begin);
        if ( comp(*right, *begin) )
            std::swap(*right, *begin);
        if ( comp(*mid, *right) )
            std::swap(*mid, *right);
        auto& pivot = *right;

        // 进行区间划分
        auto left = begin;
        for ( ; ; ) {
            // 有[begin==小值, end-1==中值]做边界
            // 遇见等于pivot的值停下作交换，若直接略过导致对于全元素相等的数组时间复杂度为O(N^2)
            for ( ; comp(*++left, pivot); );
            for ( ; comp(pivot, *--right); );
            if ( left <= right )
                std::swap(*left, *right);
            else
                break;
        }
        std::swap(*left, pivot);
        quick_sort(begin, left);
        quick_sort(left + 1, end);
    }
};


TEST(TestSuit, TestCase)
{
    std::vector<int> deal{3,1,5,2,4,0,6,9,8,7,11,12,10}, soretd{0,1,2,3,4,5,6,7,8,9,10,11,12};
    EXPECT_EQ(Solution{}.sortArray(deal), soretd);
}
