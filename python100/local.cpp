#include <iostream>

#include "mine.hpp"

int main()
{
    for( int i{}; i < 5; ++i ) {
        int local;
        std::cout << local << std::endl;
        local = i;
    }

    return 0;
}

