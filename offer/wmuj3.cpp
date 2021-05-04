#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int getit(int depth, int nr)
{
    if ( depth == 1 )
        return 0;

    int upperNr{(nr + 1) / 2};
    int upper01{getit(depth - 1, upperNr)};
    return nr & 0x1 ? upper01 : 1 - upper01;
}

int main()
{
    int depth, nr;
    std::cin >> depth >> nr;
    std::cout << getit(depth, nr);

    return 0;
}

