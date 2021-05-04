#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int main()
{
    int enemy, teamate;
    std::cin >> teamate >> enemy;
    int top{}, bot = 1e8, left = 1e8, right{0};
    for ( int i{}; i < teamate; ++i ) {
        int x, y;
        std::cin >> x >> y;
        top = std::max(top, y);
        bot = std::min(bot, y);
        left = std::min(left, x);
        right = std::min(right, x);
    }
    int cnt{};
    for ( int x{}, y{}; std::cin >> x >> y; ) {
        if ( left <= x && x <= right && bot <= y && y <= top )
            continue;
        ++cnt;
    }
    std::cout << cnt;

    return 0;
}

