#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main() {
    int sum{};
    std::cin >> sum;
    int lastNum{(sum + 1) / 2};
    std::vector<int> nums(lastNum);
    std::iota(nums.begin(), nums.end(), 1);
    int curSum{};
    for ( ssize_t begin{}, end{}; begin < nums.size(); ) {
        // 循环知道curSum >= sum
        for ( ; end < nums.size() && curSum < sum; ++end ) {
            curSum += nums[end];
        }
        if ( curSum == sum ) {
            std::copy(nums.begin() + begin, nums.begin() + end,
                    std::ostream_iterator<int>{std::cout, ","});
            std::cout << std::endl;
            curSum -= nums[begin++];
        }
        // 循环直到curSum <= sum
        for ( ; begin < nums.size() && curSum > sum; ++begin ) {
            curSum -= nums[begin];
        }
        if ( curSum == sum ) {
            std::copy(nums.begin() + begin, nums.begin() + end,
                    std::ostream_iterator<int>{std::cout, ","});
            std::cout << std::endl;
            if ( end == nums.size() )
                break;
            curSum += nums[end++];
        }
        if ( curSum < sum && end == nums.size() )
            break;
    }
}
