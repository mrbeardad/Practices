#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>


int main()
{
    int maxPric{}, miceCnt{};
    std::cin >> maxPric >> miceCnt;
    std::vector<int> prics{std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{}};
    std::sort(prics.begin(), prics.end());
    int curSum{}, minSum{std::numeric_limits<int>::max()};
    for ( ssize_t left{}, right{}, end{(ssize_t)prics.size()}; ; ) {
        for ( ; right < end && (curSum += prics[right]) < maxPric; ++right );
        if ( right >= end )
            break;
        else
            minSum = std::min(minSum, curSum);
        curSum -= prics[left++];
        curSum -= prics[right];
    }
    std::cout << minSum - miceCnt;

    return 0;
}

