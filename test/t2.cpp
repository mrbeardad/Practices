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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << __cplusplus << std::endl;

    return 0;
}
