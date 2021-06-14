#include <atomic>
#include <codecvt>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

#include "fmt/color.h"
#include "fmt/format.h"

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
    std::string pattern, text;
    std::cin >> pattern >> text;
    std::smatch sm;
    std::regex_search(text, sm, std::regex{pattern});
    fmt::print(sm.prefix().str());
    fmt::print(fg(fmt::color::red), sm.str());
    fmt::print(sm.suffix().str());

    return 0;
}

