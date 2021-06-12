#include <atomic>
#include <fmt/format.h>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "mine.hpp"

// void test_atomic()
// {
//     struct T
//     {
//         int i_;
//         double d_;
//     };
//     T t{};
//     std::atomic_ref<T> art{t};
//
// }

// void test_string()
// {
    // std::cout << fmt::format("{:4}{:4}", "熊", "海", "成") << std::endl;
// }

struct T
{
    int i_;
    double d_;

    T() : i_{} {}

    static int A_;
    static int F();
};

int main()
{
    auto ld1 = [] () {
        std::cout << 1 << std::endl;
        return 1;
    };
    auto ld2 = [] () {
        std::cout << 2 << std::endl;
        return 2;
    };

    auto a = 1 ? ld1() : ld2();

    auto* p = new T{};
    T t{};
    p->d_;
    t.d_;


    return 0;
}

