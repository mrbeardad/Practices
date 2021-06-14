#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    int min{}, max{}, times{};
    std::cin >> max >> times;
    std::vector<int> nums(max + 1);
    std::iota(nums.begin(), nums.end(), 0);
    min = max;
    max = 1;
    for ( int left{}, right{}; std::cin >> left >> right; ) {
        min = std::min(min, left);
        max = std::max(max, right);
        std::reverse(nums.begin() + left, nums.begin() + right + 1);
    }
    int cnt{};
    for ( int idx{min}; idx < max; ++idx ) {
        cnt += std::count_if(nums.begin() + idx, nums.begin() + max + 1,
                [&] (int e) {return e < nums[idx];});
    }
    std::cout << cnt;

    return 0;
}

