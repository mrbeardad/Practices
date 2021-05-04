#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> nums(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});
    int ans{};
    for ( int thisNum : nums )
        ans ^= thisNum;
    std::cout << ans;

    return 0;
}

