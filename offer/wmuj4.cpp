#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int main()
{
    std::vector<int> nums(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});
    int no{nums.back()};
    nums.pop_back();
    nums.erase(nums.end() - no);
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>{std::cout, " "});

    return 0;
}

