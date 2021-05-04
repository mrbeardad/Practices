#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

int main()
{
    int people, ads;
    std::cin >> people >> ads;
    std::vector<int> adTime(std::istream_iterator<int>{std::cin}, std::istream_iterator<int>{});
    for ( int time{}; ads; ++time ) {
        for ( size_t idx{}; idx < adTime.size(); ++idx ) {
            if ( time >= adTime[idx] && time % adTime[idx] == 0 && ads ) {
                // std::cout << adTime[idx] << ',' << time << ':';
                std::cout << idx + 1 << '\n';
                --ads;
            }
        }
    }

    return 0;
}

