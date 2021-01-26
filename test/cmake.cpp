#include <iostream>

#include "mine.hpp"

int main()
{
#ifdef NDEBUG
    std::cout << FUCK << std::endl;
#else
    std::cout << "hello" << std::endl;
#endif // FUCK

    return 0;
}

