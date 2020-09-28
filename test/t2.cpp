#include <iostream>

template <typename T>
void test(T&& t)
{
    std::cout << "outer" << std::endl;
}

 void outer()
{
    test(2);
}

