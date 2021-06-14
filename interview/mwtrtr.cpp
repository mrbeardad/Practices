#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int main()
{
    int m, n;
    while ( std::cin >> m >> n ) {
        bool anyPrint{};
        while ( m <= n ) {
            int curNum{m}, sum{};
            while ( curNum ) {
                sum += std::pow(curNum % 10, 3);
                curNum /= 10;
            }
            if ( sum == m ) {
                std::cout << m << ' ';
                anyPrint = true;
            }
            ++m;
        }
        if ( !anyPrint )
            std::cout << "no\n";
        else
            std::cout << '\n';
    }

    return 0;
}

