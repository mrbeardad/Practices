#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

// 快速选择算法
template<typename RandomIter, typename Comp=std::less<typename RandomIter::value_type> >
RandomIter topK_v1(RandomIter begin, RandomIter end, int kth,
        Comp comp=Comp{})
{
    if ( kth == 1 && end - begin == 1 )
        return begin;
    else if ( end - begin <= 1 )
        return end;

    auto mid = begin + (end - begin) / 2;
    auto last = end - 1;
    if ( comp(*begin, *last) )
        std::iter_swap(last, begin);
    if ( comp(*begin, *mid) )
        std::iter_swap(mid, begin);
    if ( comp(*last, *mid) )
        std::iter_swap(mid, last);
    auto& pivot = *last;

    auto left = begin;
    auto right = last;
    for ( ; ; ) {
        for ( ; comp(pivot, *++left); );
        for ( ; comp(*--right, pivot); );
        if ( left < right )
            std::iter_swap(left, right);
        else
            break;
    }
    std::iter_swap(left, last);

    auto nth = left - begin + 1;
    if ( nth == kth )
        return left;
    else if ( nth > kth )
        return topK_v1(begin, left, kth, comp);
    else
        return topK_v1(left + 1, end, kth - nth, comp);
}

using namespace std::placeholders;

template<typename Iter, typename Comp=std::less<typename Iter::value_type> >
Iter topK_v2(Iter begin, Iter end, int kth, Comp comp=Comp{})
{
    std::vector<Iter> topK{};
    auto reverseComp = [&comp] (auto& lhs, auto& rhs) {
        return comp(*rhs, *lhs);
    };
    auto pos = begin;
    for ( ; pos != end && topK.size() < kth; ++pos) {
        topK.emplace_back(pos);
        std::push_heap(topK.begin(), topK.end(), reverseComp);
    }
    if ( topK.size() < kth || kth <= 0 )
        throw std::logic_error{"bad kth"};
    for ( ; pos != end; ++pos ) {
        if ( comp(*topK.front(), *pos) ) {
            topK.emplace_back(pos);
            std::push_heap(topK.begin(), topK.end(), reverseComp);
            topK.pop_back();
        }
    }
    return topK.front();
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums1{1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(*topK_v1(nums1.begin(), nums1.end(), 3), 7);
    EXPECT_EQ(*topK_v2(nums1.begin(), nums1.end(), 3), 7);
    std::vector<int> nums2{9,2,1,7,3,6,7,8,9};
    EXPECT_EQ(*topK_v1(nums2.begin(), nums2.end(), 3, std::greater<int>{}), 3);
    EXPECT_EQ(*topK_v2(nums2.begin(), nums2.end(), 3, std::greater<int>{}), 3);
    std::vector<int> nums3{};
    EXPECT_ANY_THROW(topK_v1(nums3.begin(), nums3.end(), 3));
    EXPECT_ANY_THROW(topK_v2(nums3.begin(), nums3.end(), 3));
    EXPECT_ANY_THROW(topK_v1(nums2.begin(), nums2.end(), 0));
    EXPECT_ANY_THROW(topK_v2(nums2.begin(), nums2.end(), 0));
    EXPECT_ANY_THROW(topK_v1(nums2.begin(), nums2.end(), 10));
    EXPECT_ANY_THROW(topK_v2(nums2.begin(), nums2.end(), 10));

}
