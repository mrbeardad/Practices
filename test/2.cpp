#include <iostream>
struct T
{
    T()
    {
        std::cout << 'T' << std::endl;
    }
};
T t{};
