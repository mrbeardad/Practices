#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int main()
{
    double n;
    int m;
    std::cout << std::fixed << std::setprecision(2);
    while ( std::cin >> n >> m ) {
        double sum{};
        while ( m > 0 ) {
            sum += n;
            n = std::sqrt(n);
            --m;
        }
        std::cout << sum << '\n';
    }


    return 0;
}

