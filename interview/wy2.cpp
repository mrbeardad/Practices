#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    size_t cnt{};
    std::cin >> cnt;
    std::vector<int> energy(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});
    std::vector<int> oddDp(cnt), evenDp(cnt);
    oddDp[0] = energy[0];
    evenDp[0] = 0;
    for ( size_t idx{1}; idx < cnt; ++idx ) {
        oddDp[idx] = std::max(evenDp[idx - 1] + energy[idx], energy[idx]);
        evenDp[idx] = oddDp[idx - 1] - energy[idx];
    }
    std::cout << std::max(0, std::max(*std::max_element(oddDp.begin(), oddDp.end()),
            *std::max_element(evenDp.begin(), evenDp.end()))) << std::endl;
    // std::copy(oddDp.begin(), oddDp.end(), std::ostream_iterator<int>{std::cout, ","});
    // std::cout << std::endl;
    // std::copy(evenDp.begin(), evenDp.end(), std::ostream_iterator<int>{std::cout, ","});

    return 0;
}

