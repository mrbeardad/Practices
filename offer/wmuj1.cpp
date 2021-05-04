#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>

int main()
{
    std::unordered_map<int, int> nums{};
    for ( int input{}; std::cin >> input; ) {
        ++nums[input];
    }
    int cnt1_4{static_cast<int>(nums.size() * 0.25)};
    auto pos = std::find_if(nums.begin(), nums.end(), [cnt1_4, &nums] (auto& elem) {
            if ( cnt1_4 * 4 == nums.size() )
                return elem.second >= cnt1_4;
            else
                return elem.second > cnt1_4;
            });
    std::cout << pos->first;

    return 0;
}

