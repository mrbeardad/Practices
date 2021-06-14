#include <iomanip>
#include <iostream>

#include "mine.hpp"

int main()
{
    std::cout << std::setprecision(15) << std::showpoint;
    std::cout << .1 + .1 + .1 << std::endl;

    return 0;
}

