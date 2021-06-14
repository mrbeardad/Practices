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

/*! \struct T
 *  \brief Brief struct description
 *
 *  Detailed description
 */
struct T {
    T()
    {
        std::cout << "contruct T" << std::endl;
    }/*!< Description */
} /* optional variable list */;
T t{};
