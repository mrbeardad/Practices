#include <iostream>
struct T
{
    T(int i)
    {
        std::cout << 'T' << std::endl;
    }
};
T t{};
