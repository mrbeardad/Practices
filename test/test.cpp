#include <algorithm>
#include <cmath>
#include <execution>
#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <iostream>
#include <map>
#include <regex>
#include <string_view>
#include <tuple>
#include <unistd.h>

namespace
{
    class CheatSheet: public std::stringstream
    {
    public:
        CheatSheet() =default;
    };
}

void outer();

template <typename T>
void test(T&& t)
{
    std::cout << "main" << std::endl;
}

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::system("bash -c \"miro <(cat ~/.cheat/README.md)\"");

    return 0;
}

