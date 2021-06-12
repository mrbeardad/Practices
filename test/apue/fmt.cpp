#include <chrono>
#include <iostream>

#include "fmt/chrono.h"
#include "fmt/color.h"
#include "fmt/format.h"
#include "fmt/ranges.h"

#include "mine.hpp"

enum class emphasis : uint8_t {
  bold = 1,
  italic = 1 << 1,
  underline = 1 << 2,
  strikethrough = 1 << 3
};

int main()
{
    // fmt::print(fmt::emphasis::italic, "");
    // std::vector<int> v{1,2,3,4,5};
    // fmt::print("\n{}", v);
    std::string s{"熊海成爸爸de🏠"};
    std::cout << fmt::detail::count_code_points(s);

    return 0;
}

