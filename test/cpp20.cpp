#include <atomic>
// #include <fmt/format.h>
#include <iostream>
#include <numeric>
#include <string>

#include "mine.hpp"

void test_atomic()
{
    struct T
    {
        int i_;
        double d_;
    };
    T t{};
    std::atomic_ref<T> art{t};
    
}

// void test_string()
// {
    // std::cout << fmt::format("{:4}{:4}", "熊", "海", "成") << std::endl;
// }

int main()
{
    std::cout << std::midpoint(1, 2) << std::endl;

    return 0;
}

